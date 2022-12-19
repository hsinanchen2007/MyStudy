### 解题思路
插入后排序

### 代码

```c

int comp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i =n;
while(i--)
{
A[m+i]=B[i];
}
qsort(A,m+n,sizeof(int),comp);
}


```