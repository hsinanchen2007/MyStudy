
按右、下、左、上四个方向顺序写
将二维数组赋0
若超出边界或下一个值不为0则改变方向
```
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    if(n<=0){
        *returnSize = 0;
        *returnColumnSizes = (int *)malloc(sizeof(int)); 
        **returnColumnSizes = 0;
        return NULL;
    }
    int direction = 0;
    int **matrix = (int**)malloc(n*sizeof(int*));
    for(int i = 0;i<n;i++){
        matrix[i] = (int *)malloc(n*sizeof(int));
        memset(matrix[i],0,sizeof(int)*n);
    }
    *returnColumnSizes = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        *(*returnColumnSizes + i) = n;
    }
    *returnSize = n;
    int i = 0,j=0;
    int count = 1;
    while(count<=n*n){
    if(direction == 0){
            do{
                matrix[i][j++] = count++;
        }while(j!=n&&matrix[i][j]==0);
        j = j-1;
        i++;
        direction = 1;
    }
    else if(direction == 1){
            do{
                matrix[i++][j] = count++;
        }while(i!=n&&matrix[i][j]==0);
        i = i-1;
        j--;
        direction = 2;
    }
    else if(direction == 2){
            do{
                matrix[i][j--] = count++;
        }while(j!=-1&&matrix[i][j]==0);
        j++;
        i--;
        direction = 3;
    }
    else{
            do{
                matrix[i--][j] = count++;
        }while(i!=-1&&matrix[i][j]==0);
        i++;
        j++;
        direction = 0;
    }
    }
    return matrix;
}
```