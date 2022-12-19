### 解题思路

### 代码

```c
void merge(int *A, int ASize, int m, int *B, int BSize, int n)
{
    for (int i = 0; i < n; i++)
    {
        A[i + m] = B[i];
        ASize++;
    }
    for (int i = 0; i < m + n; i++)
    {
        for (int j = i + 1; j < m + n; j++)
        {
            int t;
            if (A[j] < A[i])
            {
                t = A[j];
                A[j] = A[i];
                A[i] = t;
            }
        }
    }
}
```