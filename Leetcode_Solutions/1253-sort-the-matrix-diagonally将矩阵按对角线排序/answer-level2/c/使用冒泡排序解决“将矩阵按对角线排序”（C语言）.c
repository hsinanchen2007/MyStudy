### 解题思路
向右下方冒泡排序。

![image.png](https://pic.leetcode-cn.com/2e3e17d0bc752f7244116fd80a0da9bd85bd1eefbae3629cc02dbc9daed30370-image.png)


### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// 【算法思路】冒泡排序。每行向右下方进行排序
int** diagonalSort(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){
    int row = matSize;
    int col = matColSize[0];

    for(int i = 0; i < row - 1; i++)
    {
        for(int j = 0; j < row - 1 - i; j++)
        {
            // 最内层遍历，比较mat[j][k]和mat[j + 1][k + 1]
            for(int k = 0; k < col - 1; k++)
            {
                if(mat[j][k] > mat[j + 1][k + 1])
                {
                    int tmp = mat[j][k];
                    mat[j][k] = mat[j + 1][k + 1];
                    mat[j + 1][k + 1] = tmp;
                }
            }
        }
    }

    *returnSize = matSize;
    *returnColumnSizes = matColSize;
    return mat;
}
```