### 解题思路
先用快排，然后判断k是否大于等于最大值的二分之一，如果是，返回最小差值0.否的话返回最大值减K与最小值加-K的差值。

### 代码

```c
int smallestRangeI(int* A, int ASize, int K){
    int f(int* a,int* b)
    {
        return *a>*b?1:0;
    }
    qsort(A,ASize,sizeof(int),f);
    if(K>=A[ASize-1]/2)
    {
        return 0;
    }
    else
    return A[ASize-1]-K-(A[0]+K);
}
```