### 解题思路
出口参数说明：
* returnSize：输出行数的地址
** returnColumnSizes：输出每行元素个数的地址
返回值：输出杨辉三角矩阵的地址

### 代码

```c
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int **s;
    int i, j;

    s = (int **)malloc(sizeof(int *) * numRows);
    *returnColumnSizes = (int *)malloc(sizeof(int) * numRows);

    for (i = 0; i<numRows; i++) {
        s[i] = (int *)malloc(sizeof(int) * (i + 1));
        (*returnColumnSizes)[i] = i + 1;
        s[i][0] = 1;

        if (i>1) {
            s[i][i] = 1;
            for (j = 1; j<i; j++) {
                s[i][j] = s[i - 1][j - 1] + s[i - 1][j];                
            }
        }
        else {
            if (i == 1) {
                s[1][1] = 1;
            }            
        }
    }

    *returnSize = numRows;

    return s;

}
```