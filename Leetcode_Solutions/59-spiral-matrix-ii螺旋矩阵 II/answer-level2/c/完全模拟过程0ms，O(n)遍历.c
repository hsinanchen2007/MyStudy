### 解题思路
完全模拟过程，上下左右四个边界
起始向右走，curCol++，走到了右上角，方向转为向下走，上边界下移；
如果向下走，curRow++，走到了右下角，方向转为向左走，右边界左移；
如果向左走，curCol--，走到了左下角，方向转为向上走，下边界上移；
如果向上走，curRow--，走到了左上角，方向转为向右走，左边界右移；
退出条件是curValue == maxValue(n * n)

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef enum {
    UP = 1,
    DOWN,
    LEFT,
    RIGHT,
} Move;

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    if (n == 0 || returnSize == NULL) {
        return NULL;
    }
    *returnColumnSizes = (int *)malloc(sizeof(int) * n);
    int **ret = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        ret[i] = (int *)malloc(sizeof(int) * n);
        *(*returnColumnSizes + i) = n;
    }
    *returnSize = n;
    int maxValue = n * n, curValue = 1, curRow = 0, curCol = 0;
    Move mov = RIGHT;
    int top = 0, left = 0, right = n - 1, floor = n - 1;
    while (curValue <= maxValue) {
        ret[curRow][curCol] = curValue;
        switch (mov) {
            case UP:
                curRow--;
                if (curRow == top && curCol == left) {
                    mov = RIGHT;
                    left++;
                }
                break;
            case DOWN:
                curRow++;
                if (curRow == floor && curCol == right) {
                    mov = LEFT;
                    right--;
                }
                break;
            case LEFT:
                curCol--;
                if (curRow == floor && curCol == left) {
                    mov = UP;
                    floor--;
                }
                break;
            case RIGHT:
                curCol++;
                if (curRow == top && curCol == right) {
                    mov = DOWN;
                    top++;
                }
                break;
            default:
                break;
        }
        curValue++;
    }
    return ret;
}
```