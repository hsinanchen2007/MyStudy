### 解题思路
此处撰写解题思路

（1）循环遍历数组，直至两次更改的次数完全相同；

注意：
（1）每次循环遍历过程中，需要把腐烂的橘子上下左右的好橘子都变为坏橘子，此时次数只能+1；
（2）当所有的橘子都是坏橘子的时候就可以直接退出了
（3）每次遍历的时候需要把坏橘子周围的好橘子设置成3，防止篡改，后续遍历再改成坏橘子


### 代码

```c
int orangesRotting(int** grid, int gridSize, int* gridColSize){
    int row, col;
    int cnt, new_cnt, i, j, flag;

    row = gridSize;
    col = *gridColSize;

    cnt = 0;
    new_cnt = -1;
    /* 循环遍历数组，直至前后两次完全相同 */
    while (new_cnt != cnt) {
        new_cnt = cnt;
        flag = 0;
        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    if ((i > 0 && (grid[i - 1][j] == 1)) || 
                        (i < row - 1 && (grid[i + 1][j] == 1)) ||
                        (j > 0 && (grid[i][j - 1] == 1)) || 
                        (j < col - 1 && (grid[i][j + 1] == 1))) {
                            if (flag == 0) {
                                flag = 1;
                                cnt++;    
                            }
                        }
                    if (i > 0 && (grid[i - 1][j] == 1)) { /* up */
                        grid[i - 1][j] = 3;
                    }
                    if (i < row - 1 && (grid[i + 1][j] == 1)) { /* down */
                        grid[i + 1][j] = 3;
                    }
                    if (j > 0 && (grid[i][j - 1] == 1)) { /* left */                   
                        grid[i][j - 1] = 3;
                    }
                    if (j < col - 1 && (grid[i][j + 1] == 1)) { /* right */
                        grid[i][j + 1] = 3;
                    }
                }
            }
        }

        for (i = 0; i < row; i++) {
            for (j = 0; j < col; j++) {
                if (grid[i][j] == 3) {
                    grid[i][j] = 2;
                }
            }
        }
    }
        
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }

    return cnt;
}

```