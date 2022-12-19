### 解题思路
此处撰写解题思路

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    if(ASize < m+n) return;
    int i, j, temp;
    memcpy(&A[m], &B[0], n*sizeof(int));
    for(i = 0; i<m+n; i++)
    {
        for(j=i+1; j<m+n; j++)
        {
            if(A[i]>A[j])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
}
```