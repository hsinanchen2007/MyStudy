### 解题思路
将第二个数组加入到第一个数组之后 利用qsort进行排序既可得到有序数组

### 代码

```c
int cmp(const void*a,const void*b)
{
    return *(int *)a-*(int *)b;
}
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int j = 0;
    for(int i = m;i<ASize;i++)
    {
        A[i] = B[j];
        j++;
    }
    qsort(A,m+n,sizeof(int),cmp);
    return A;
}
```