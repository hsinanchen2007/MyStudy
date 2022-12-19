### 解题思路
此处撰写解题思路

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    for (int i = m, j = 0; i < ASize && j < n; i++, j++)
    {
        A[i] = B[j];
    }
    int w;
    for (int i = 0; i < ASize; i++)
    {
        for (int j = 0; j < ASize; j++)
        {
            if (A[i] < A[j])
            {
                w = A[i];
                A[i] = A[j];
                A[j] = w;
            }
        }
    }
}
```