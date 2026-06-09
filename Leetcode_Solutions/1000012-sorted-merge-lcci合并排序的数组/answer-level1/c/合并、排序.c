### 解题思路
先合并 再排序

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int i;
    for(i=0;i<n;++i)
    A[m+i]=B[i];

    for(i=0;i<ASize-1;++i)
    {
        int j;
        for(j=0;j<ASize-i-1;++j)
            if(A[j]>A[j+1])
            {
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
    }
    return A;
}
```