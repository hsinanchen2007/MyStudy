### 解题思路
此处撰写解题思路
这是我写过感觉很满意的代码，优秀的代码阅读起来一定也很容易。
![image.png](https://pic.leetcode-cn.com/b17e9f72128721079817f8cd48d0bdc8fbdc65141a9c4a28e5126c3666f7def9-image.png)

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int **res = calloc(n, sizeof(int*));
    *returnSize = n;
    *returnColumnSizes = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        res[i] = calloc(n, sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    int i = 1;
    int row, col, r, c;
    r = col = -1;

    while (i <= n * n) {
        //right
        row = r + 1;
        for (c = col + 1; c < n && res[row][c] == 0; c++) {
            res[row][c] = i;
            i++;
        }

        //down
        col = c - 1;
        for (r = row + 1; r < n && res[r][col] == 0; r++) {
            res[r][col] = i;
            i++;
        }

        //left
        row = r - 1;
        for (c = col - 1; c >= 0 && res[row][c] == 0; c--) {
            res[row][c] = i;
            i++;
        }

        //up
        col = c + 1;
        for (r = row - 1; r >= 0 && res[r][col] == 0; r--) {
            res[r][col] = i;
            i++;
        }

    }

    return res;
}
```