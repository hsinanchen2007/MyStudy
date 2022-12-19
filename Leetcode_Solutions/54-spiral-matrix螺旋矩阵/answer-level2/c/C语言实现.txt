```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize)
{
        if( matrix == NULL || matrixColSize == NULL || returnSize == NULL || matrixSize == 0 )  // 传过来一个[]
        {
                *returnSize = 0;
                return NULL;
        }
        int *ret = (int *) malloc(sizeof(int) * matrixSize * (*matrixColSize));
        *returnSize = 0;

        int row=0, col=0;
        int max = matrixSize * (*matrixColSize);
        printf("max:%d\n",max);   
        int tmp = 0, count = 0;
        while(count < max)
        {
                for(row=tmp,col=tmp; col<*matrixColSize-tmp; col++)
                {
                        printf("%d ",matrix[row][col]);
                        ret[count++] = matrix[row][col];
                }
                if(count>=max)
                        break;
                printf("\n");
                for(++row,--col; row<matrixSize-tmp; row++)
                {
                        printf("%d ",matrix[row][col]);
                        ret[count++] = matrix[row][col];
                }
                if(count>=max)
                        break;
                printf("\n");
                for(--row,--col; col>-1+tmp; col--)
                {
                        printf("%d ",matrix[row][col]);
                        ret[count++] = matrix[row][col];
                }
                if(count>=max)
                        break;
                printf("\n");
                for(--row,++col; row>0+tmp; row--)
                {
                        printf("%d ",matrix[row][col]);
                        ret[count++] = matrix[row][col];
                }
                if(count>=max)
                        break;
                printf("\n");
                tmp++;
        }  
        printf("count:%d\n",count);   
        *returnSize = max;
        return ret;
}
```
