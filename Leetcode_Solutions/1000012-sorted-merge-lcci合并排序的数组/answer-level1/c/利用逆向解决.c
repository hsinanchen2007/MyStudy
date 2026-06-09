### 解题思路
此处撰写解题思路

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int k=m+n-1;
    m=m-1;
    n=n-1;
    while(m>=0 && n>=0)
    {
        if(A[m]>=B[n])
        {
            A[k--]=A[m--];
        }
        else
        {
            A[k--]=B[n--];
        }
    }
    while(n>=0)
    {
        A[k--]=B[n--];
    }
}
```