分别统计行和列出现的次数的奇偶性，然后行列进行重合，奇偶性相同为偶数，不同为奇数
```
int oddCells(int n, int m, int** indices, int indicesSize, int* indicesColSize)
{
    int res = 0;
    int i, j;
    int *a = (int*)malloc(n * sizeof(int));
    memset(a, 0, n*sizeof(int));
    int *b = (int*)malloc(m * sizeof(int));
    memset(b, 0, m*sizeof(int));
    for (i = 0; i < indicesSize; i++)
    {
        a[indices[i][0]] = (a[indices[i][0]]+1)%2;
        b[indices[i][1]] = (b[indices[i][1]]+1)%2;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (a[i] != b[j])
                res++;
        }
    }
    return res;
}
```
