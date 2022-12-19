### 解题思路
思路和spiral matrix 2相同,赋值那段逆向操作即可
![图片.png](https://pic.leetcode-cn.com/fe9f44712e0a9d60785ee3c9e275ceb00e4b83a644a1bbb7e30cf7d2c405840e-%E5%9B%BE%E7%89%87.png)


### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    if (n == 0 || returnSize == NULL) {
        return NULL;
    }
    int **matrix=(int **)malloc(sizeof(int*)*n);
    *returnColumnSizes = (int *)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        matrix[i]=(int*)malloc(sizeof(int)*n);
         *(*returnColumnSizes+i)=n;
    }
    int c=1;
    int up=0,down=n-1,left=0,right=n-1;
    while(up<=down&&left<=right){
        for(int i=left;i<=right;i++){
            matrix[up][i]=c++;
        }
        up++;
        if(up>down){
            break;
        }
        for(int i=up;i<=down;i++){
            matrix[i][right]=c++;
        }
        right--;
        if(left>right){
            break;
        }
        for(int i=right;i>=left;i--){
           matrix[down][i]=c++;
        }
        down--;
        if(up>down){
            break;
        }
        for(int i=down;i>=up;i--){
            matrix[i][left]=c++;
        }
        left++;
        if(left>right){
            break;
        }
    }
    *returnSize=n;  
    return matrix;
}
```