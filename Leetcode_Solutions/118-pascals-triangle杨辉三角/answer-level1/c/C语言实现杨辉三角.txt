```
int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    int** arr= malloc(sizeof(int*)*numRows);
    *returnColumnSizes = malloc(sizeof(int)*numRows);
    for(int i=0;i<numRows;i++)
    {
        arr[i] = (int *)malloc(sizeof(int)*(i+1));
        (*returnColumnSizes)[i] = i+1;
        if(i==0)
        {
            arr[0][0]=1;  
        }
        else
        {
            for(int j=0;j<=i;j++)
            {
                if( j ==0 || j == i)
                {
                    arr[i][j] = 1;   
                }
                else
                {   
                    arr[i][j] = arr[i-1][j-1]+arr[i-1][j];                             }
            }
        }
    }
    *returnSize = numRows;
    return arr;
}
```
