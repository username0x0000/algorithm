# Ch 3. 검색



## 03 - 1

### 검색과 키

```
1. 국적이 한국인 사람을 찾는다
2. 나이가 21세 이상 27세 미만인 사람을 찾는다.
3. 어떤 낱말과 발음이 가장 비슷한 이름의 사람을 찾는다.
```

- 키 ( key ) : 검색을 하고자 하는 목적 / ex) 나이를 검색하는 경우 나이가 키 ( key ) 이다



### 배열에서 검색하기

```
a : 배열 검색
	1. 선형 검색 : 무작위로 늘어놓은 데이터 모임에서 아주 빠른 검색을 수행합니다.
	2. 이진 검색 : 일정한 규칙으로 늘어놓은 데이터 모임에서 아주 빠른 검색을 수행합니다
	3. 해시법 : 추가, 삭제가 자주 일어나는 데이터 모임에서 아주 빠른 검색을 수행합니다
		- 체인법 : 같은 해시 값의 데이터를 선형 리스트로 연결하는 방법
		- 오픈 주소법 : 데이터를 위한 해시 값이 충돌할 때 재해시하는 방법
b : 선형 리스트 검색
c : 이진검색트리 검색
```

- a : 배열 검색

  ```c
  #include<stdio.h>
  
  int main(void){
  
     int i;
     int nums[] = {50, 30, 100, 10, 60, 40, 70, 80, 90, 20};
     int num;
  
     printf("num : ");
     scanf("%d", &num);
  
     for(i = 0; i < 10; ++i){
        if(num == nums[i])   // 입력한 숫자가 nums[] 배열안에 저장되어 있으면,
           break;            // for 문을 빠져나온다.
     }
  
     if(i < 10)   // for 문을 빠져나왔을 때 i가 10보다 작다면, 입력한 숫자가 배열안에 존재한다.
        printf("fount! index : %d\n", i);
     else
        printf("not found!\n");
  
     return 0;
  }
  ```

  - 선형 검색

    ```c
    #include <stdio.h>
    
    int search(int num[], int target, int length)
    {
        int i = 0;
        while(1)
        {
            if(length == i)
            {
                return -1;
            }
            if(num[i] == target)
            {
                return i;
            }
        }
    }
    
    int main()
    {
        int target, idx;
        int num[5] = {1, 2, 3, 4, 5};
        
        printf("검색할 값 : ");
        scanf("%d", &target);
        
        idx = search(num, target, 5);
        
        if(idx == -1)
        {
            printf("찾는 값이 없습니다. \n");
        }
        else
        {
            printf("%d는 num[%d]에 있습니다. \n", target, num[idx-1]);
        }
    }
    ```

  - 이진검색

    ```c
    #include<stdio.h>
    
    int main() {
        int target,low,high,mid;
        int data[10] = { 2,3,5,7,8,9,11,13,15,20 };
        
        scanf_s("%d", &target);
        low = 0; //search대상범위의 첫번째값 
        high = 9; //search대상범위의 마지막값
        
        while (low <= high) {
            mid = (low + high) / 2;
            if (target == data[mid]) { //탐색 성공
                printf("%d는 %d번째 index에 있습니다.", target, mid);
                return 0;
            }
            else if (target < data[mid]) { // 탐색 범위 재조정 low ~ mid-1
                high = mid - 1;
            }
            else if (target > data[mid]) { // 탐색 범위 재조정 mid+1 ~ high
                low = mid + 1;
            }
        }
        
        printf("%d는 존재하지 않습니다.", target);
        return 0;
    }
    ```

  - 해시법

    ```c
    어려워서 조금 더 공부가 필요
    ```

- b : 선형 리스트 검색

  ```c
  1. 데이터 삽입 : 빈칸 확보 -> 자리 이동 -> 데이터 삽입 
  
  ex) a - b - c 선형 리스트에 d를  b와 c 사이에 삽입 -> a - b - c - * ( 빈칸 확보 ) -> a - b - * - c ( 자리 이동 ) -> a - b - d - c ( 데이터 삽입 )
  
   
  
  2. 데이터 삭제 : 데이터 삭제 -> 자리 이동 -> 빈칸 제거
  
  ex) a - b - c - d 선형 리스트에서 b를 삭제 -> a - * - c - d ( 데이터 삭제 ) -> a - c - * - d -> a - c - d - * ( 자리 이동 ) -> a - c - d ( 빈칸 제거 )
  ```

- c : 이진검색트리 검색

  ![img](https://ehpub.co.kr/wp-content/uploads/2022/05/5-16.png)

  이렇듯, 이진검색의 방법을 중첩으로 이용하는 느낌이다.



- 데이터의 추가 비용이 더 많이 드는가?
  - 이 부분은 경우에 따라 달라지는데, 순서대로 키의 값을 넣은 배열이 있다고 가정할 경우 번호만 알면 키값을 알 수 있지만, 데이터를 중간에 끼워 넣어야 하는 경우에는 넣으려는 위치 뒤의 값들은 뒤로 밀어야 하는 경우가 있다. 이런 경우를 " 배열은 검색은 빠르지만, 데이터를 추가하기 위한 비용이 많이 든다 " 라고 한다.