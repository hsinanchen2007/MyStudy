### 解题思路
在碰到矩阵边界时，分情况判断。其他情况根据direction方向，进行操作。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(matrixSize==0 || *matrixColSize==0)
    {
        *returnSize = 0;
        return NULL;
    }
    int index=0,i=0,j=0;
    int direction=1;   //方向，1代表向上，0代表向下
    int *ret=malloc(sizeof(int) * matrixSize * (*matrixColSize));
    while(index < matrixSize * (*matrixColSize))
    {
        ret[index++]=matrix[i][j];
        if(i==0 && direction==1)      //碰到上边界
        {
            if(j<(*matrixColSize-1))
            {
                j++;
                direction=0;
            }
            else        //右上角
            {
                i++;
                direction=0;
            }
        }
        else if(j==0 && direction==0)    //碰到左边界
        {
            if(i<matrixSize-1)
            {
                i++;
                direction=1;
            }
            else         //左下角
            {
                j++;
                direction=1;
            }
        }
        else if(i==matrixSize-1 && direction==0)    //碰到下边界
        {
            if(j<(*matrixColSize-1))
            {
                j++;
                direction=1;
            }
            else         //碰到右下角，什么也不做（结束）
                continue;
        }
        else if(j==*matrixColSize-1 && direction==1)   //碰到右边界
        {
            if(i<matrixSize-1)
            {
                i++;
                direction=0;
            }
            else       //碰到右下角，什么也不做（结束）
                continue;
        }
        else     //其他情况
        {
            if(direction==0)
            {
                i++;
                j--;
            }
            else
            {
                i--;
                j++;
            }
        }
    }
    *returnSize=matrixSize * (*matrixColSize);
    return ret;
}
```