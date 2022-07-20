# Ch. 5 재귀 알고리즘



## 05 - 1 재귀의 기본

- 재귀 : 어떤 사건이 자기 자신을 포함하고 다시 자기 자신을 사용하여 정의될 때 재귀적이라고 한다. 

  - Factorial ( 순차곱셈 )

    ```c
    #include <stdio.h>
    
    int factorial(int n)
    {
        if(n > 0)
        {
            return n * factorial(n - 1);
        }
        else
        {
            return 1;
        }
    }
    
    int main()
    {
        int x;
        printf("정수를 입력하세요. : ");
        scanf("%d", &x);
        printf("%d의 순차곱셈 값은 %d입니다. \n", x, factorial(x));
        
        return 0;
    }
    ```



- 재귀 호출

  - 유클리드 호제법

    ```c
    #include <stdio.h>
    
    int gcd(int x, int y)
    {
        if(y == 0)
        {
            return x;
        }
        else
        {
            return gcd(y, x % y);
        }
    }
    
    int main()
    {
        int x, y;
        puts("두 정수의 최대공약수를 구합니다.");
        printf("정수를 입력하세요 : ");
        scanf("%d", &x);
        printf("정수를 입력하세요 : ");
        scanf("%d", &y);
        printf("최대공약수는 %d입니다. \n", gcd(x, y));
        
        return 0;
    }
    ```

    

## 05 - 2 재귀 알고리즘 분석

- 재귀 알고리즘을 분석에는 하향식 ( top down ) 분석과 상향식 ( bottom up ) 분석이 있다.

  - 재귀 알고리즘의 분석

    ```c
    #include <stdio.h>
    
    void recur(int n)
    {
        if(n > 0)
        {
            recur(n - 1);
            printf("%d\n", n);
            recur(n - 2);
        }
    }
    
    int main()
    {
        int x;
        printf("정수를 입력하세요 : ");
        scanf("%d, &x");
        recur(x);
        
        return 0;
    }
    
    // 하향식 분석 : 
    	n에 4를 전달하면 recur 함수는 아래 과정을 순서대로 실행한다.
    	recur(3)을 실행한다.
        4를 출력한다.
    	recur(2)를 실행한다.
            
    // 상향식 분석 :
    	n이 양수일 때만 실행하므로 recur(1)을 먼저 해야 한다.
    	recur(1)은 recur(0)을 실행한다.
    	1을 출력한다.
    	recur(-1)을 실행한다.
    	recur(0)과 recur(-1)은 출력할 내용이 없다.
    	그러므로 recur(2)를 보면, recur(1)을 실행한다.
    	2를 출력한다.
    	recur(0)을 실행한다.
    	recur(1)은 1을 출력하고 recur(0)은 출력 할 내용이 없다.
    	전체 과정을 거치면 1과 2를 출력한다.
    	이 작업을 recur(4)까지 쌓아 올려 과정을 거치면 recur(4)가 출력된다.
    ```
    



- 재귀 알고리즘의 비재귀적 표현

  - 꼬리 재귀의 제거

    ```c
    void recur(int n)
    {
        Top :
        	if(n > 0)
            {
                recur(n - 1)
    			printf("%d\n", n);
                n = n - 2;
                goto Top;
            }
    }
    	// goto문을 사용해서 꼬리재귀를 제거하는 방법
    ```

  - 스택을 이용한 비재귀적 recur 함수

    ```c
    void recur(int n)
    {
        IntStack stk;
        Initialize(&stk, 100);
    	Top :
    		if(n > 0)
            {
                Push(&stk, n);
                n = n - 1;
                goto Top;
            }
        	if(!IsEmpty(&stk))
            {
                Pop(&stk, &n);
                printf("%d\n", n);
                n = n - 2;
                goto Top;
            }
        
        Terminate(&stk);
    }
    
    // recur(4)를 호출하는 과정
    // 4를 스택에 푸쉬하면, n의 값을 하나 줄여서 3으로 만든다.
    // 그 후 goto문에 의해서 레이블이 Top으로 돌아간다.
    ```

    

