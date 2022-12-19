### 解题思路
奥里给，干就完了！

qsort排序，然后再依次看进行不重复操作

### 代码

```c
int cmp(void *a,const void *b)
{
    return (*(int*) a -*(int*) b); //强制类型转化
}
int minIncrementForUnique(int* A, int ASize){
    qsort(A,ASize,sizeof(int),cmp);//快速排序，不严格递增

    int cnt=0;
    for(int i=1;i<ASize;i++)
    {
        //特殊相等情况，后一个应该比前一个大
        if(A[i]<=A[i-1]){
            cnt+=A[i-1]-A[i]+1;
            A[i]=A[i-1]+1;
        }
    }
    return cnt;
}
/*
int compFun(void *a, void *b)
{
    return (*(int*)a - *(int*)b);
}

int minIncrementForUnique(int* A, int ASize)
{
    qsort(A, ASize, sizeof(int), compFun);
    int cnt = 0;
    for (int i = 1; i < ASize; i++) {
        if (A[i] <= A[i - 1]) {
            cnt += A[i - 1] + 1 - A[i];
            A[i] = A[i - 1] + 1;
        }
    }
    return cnt;
}
```