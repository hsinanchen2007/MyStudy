/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int** ret;
    int i, j;
    
    if((ret = (int** )malloc(numRows * sizeof(int* ))) != NULL)
    {
        *returnColumnSizes = (int* )malloc(numRows * sizeof(int));

        *returnSize = numRows;

        if(numRows == 0)
        {
            return ret;
        }

        for(i = 0; i < numRows; i++)
        {
            ret[i] = (int* )malloc((i + 1) * sizeof(int));

            (*returnColumnSizes)[i] = i + 1;

            for(j = 0; j <= i; j++)
            {
                if((j == 0) || (j == i))
                {
                    ret[i][j] = 1;
                }
                else
                {
                    ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
                }
            }
        }
    }

    return ret;
}