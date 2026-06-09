```
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(matrixSize == 0||matrix == NULL)
    {
        *returnSize = 0;
        return 0;
    }
    int index = 0, i = 0, r1 = 0, r2 = matrixSize - 1, c1 = 0, c2 = matrixColSize[0] - 1;
    int *res = (int *)malloc(sizeof(int) * (matrixSize * matrixColSize[0]));
    int count = 0;
    while(r1 <= r2 && c1 <= c2)
    {
        for(i = c1;i <= c2;i++)
        {
            count++;
            res[index++] = matrix[r1][i];
        }
        for(i = r1 + 1;i <= r2;i++)
        {
            count++;
            res[index++] = matrix[i][c2];
        }
        if(r1 != r2)
        {
            for(i = c2 - 1;i >= c1;i--)
            {
                count++;
                res[index++] = matrix[r2][i];
            }
        }
        if(c1 != c2)
        {
            for(i = r2 - 1;i > r1;i--)
            {
                count++;
                res[index++] = matrix[i][c1];
            }
        }
        r1++;r2--;c1++;c2--;
    }
    *returnSize = count;
    return res;
}
```
