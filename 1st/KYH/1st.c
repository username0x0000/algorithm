#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int height;
    int weight;
} Person;

void SetHegithWeight(Person *a)
{
    for(char i = 0; i < 8; ++i)
    {
        a[i].height = 150 + rand() % 50;
        a[i].weight = 50 + rand() % 40;
    }
}

void Print_Person(Person *a)
{
    for(int i = 0; i < 8; ++i)
    {
        printf("이름 : %s, 키 : %d cm, 몸무게 : %d kg \n", a[i].name, a[i].height, a[i].weight);
    }
}

int Person_cmp(const Person *a, const Person *b)
{
    return (a->height > b->height) ? 1 : ((a->height < b->height) ? -1 : 0);
}

int main()
{
    Person a[9] = {{"김민수"}, {"나철수"}, {"도민준"}, {"라시현"}, {"마동석"}, {"백장미"}, {"소공녀"}, {"유재석"}, {"검색에 실패했습니다."}};
    srand(time(NULL));
	SetHegithWeight(a);
    Print_Person(a);
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(a[i].height == a[j].height)
                SetHegithWeight(a);
        }
    }
    printf("키 순으로 정렬합니다.");
    for(int i = 0; i < 7; ++i)
    {
        Person TempPerson = a[i];
        if(TempPerson.height > a[i + 1].height)
        {
            a[i] = a[i + 1];
            a[i + 1] = TempPerson;
            i = 0;
        }
    }
    Print_Person(a);

    Person key = {" "};
    printf("찾고 싶은 키를 입력해주십시오 : ");
    scanf("%d", &key.height);

    Person *Result;
    Result->height = (int*)bsearch(&key, a, 9, sizeof(Person), (int(*) (const void*, const void*)) Person_cmp);
    
    printf("%s", Result->name);
}