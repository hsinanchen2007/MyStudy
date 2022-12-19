### 解题思路
先找到‘0’点，再从该点开始上下左右遍历找‘E’，遇到‘W’就结束。

### 代码

```c
int GetMax(int a, int b)
{
    if (a > b) {
        return a;
    }
    return b;
}

int Caculat(char **grid, int gridSize, int gridColSize, int row, int col)
{
    int         count       = 0;

    /* caculate row */
    for (int loopI = col; loopI < gridColSize; loopI++) {
        if (grid[row][loopI] == 'E') {
            count++;
        }
        if (grid[row][loopI] == 'W') {
            break;
        }
    }
    for (int loopI = col - 1; loopI >= 0; loopI--) {
        if (grid[row][loopI] == 'E') {
            count++;
        }
        if (grid[row][loopI] == 'W') {
            break;
        }
    }

    /* caculate col */
    for (int loopI = row; loopI < gridSize; loopI++) {
        if (grid[loopI][col] == 'E') {
            count++;
        } 
        if (grid[loopI][col] == 'W') {
            break;
        }
    }
    for (int loopI = row - 1; loopI >= 0; loopI--) {
        if (grid[loopI][col] == 'E') {
            count++;
        } 
        if (grid[loopI][col] == 'W') {
            break;
        }
    }

    return count;
}

int maxKilledEnemies(char** grid, int gridSize, int* gridColSize)
{
    int         max         = 0;
    int         curValue    = 0;

    if ((grid == NULL) || (gridColSize == NULL) || (gridSize <= 0)){
        return 0;
    }

    if (gridColSize[0] <= 0) {
        return 0;
    }

    for (int loopI = 0; loopI < gridSize; loopI++) {
        for (int loopJ = 0; loopJ < gridColSize[0]; loopJ++) {
            if (grid[loopI][loopJ] == '0') {
                curValue        = Caculat(grid, gridSize, gridColSize[0], loopI, loopJ);
                max             = GetMax(max, curValue);
            }
        }
    }
    return max;
}

```