### 解题思路
此处撰写解题思路

### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize)
{
    int temp;
    int i = 0,j = 0;
    for(i;i < matrixSize;i++,j++)
    {
        for(j = i+1;j<matrixSize;j++)
        {           
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;             
        }
    }
    i = 0;
    j = matrixSize-1;
    int k = 0;
    while(i<matrixSize)
    {   
        k = 0;
        j = matrixSize-1;    
        while(k<j)
        {
            temp = matrix[i][k];
            matrix[i][k] = matrix[i][j];
            matrix[i][j] = temp;
            k++;j--;
        }
        i++;
    }    
}
```