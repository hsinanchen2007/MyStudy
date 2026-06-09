### 解题思路

没想到吧，这居然也是动态规划。动态规划就是多阶段决策模型，而我们的杨辉三角，就是先算一层，在算一层。

这里的状态转移方程就是`res[i][j] = res[i-1][j] + res[i-1][j-1];`

不过用C语言处理的问题就在于理解参数 `int *returnSize`, 我能理解，就是返回二维数组的行数 但是 **returnColumnSizes, 我就理解不能了,
.解释上说 `*returnColumnSizes` 用于确定数组的大小，那一个`*`就够了呀，为啥给我两个。总之后续就按照它说的来吧。

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// 

int** generate(int numRows, int* returnSize, int** returnColumnSizes){

    if (numRows == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    //返回的行数
    *returnSize = numRows; //
    //返回的列数, 一个一维数组
    *returnColumnSizes =  (int *)malloc(sizeof(int) * numRows);
    //确定每行的大小
    for (int i = 0; i < numRows; i++){
         (*returnColumnSizes)[i] = i+1;  
    }

    //输出结果
    int **res = (int **)malloc(sizeof(int *) * numRows);
    //第一行
    res[0] = (int*)malloc(sizeof(int) );
    res[0][0] = 1;

    for (int i = 1; i < numRows; i++){
        res[i] = (int *)malloc(sizeof(int) * (i+1));
        for (int j = 0; j < (i+1); j++){
            if (j == 0 || j == i){
                res[i][j] = 1;
            } else{
                res[i][j] = res[i-1][j] + res[i-1][j-1];
            }
        }
    }
    return res;

}
```