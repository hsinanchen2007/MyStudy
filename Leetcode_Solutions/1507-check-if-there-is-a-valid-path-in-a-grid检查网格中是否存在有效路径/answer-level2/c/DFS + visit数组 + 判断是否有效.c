### 解题思路
DFS 算法，
1. 遍历4个方向，若可以连通且未访问过则判断为有效
2. 找到目的地则直接返回true
3. 找不到则返回false

### 代码

```c

#define MAX_DIRECT 4
#define MAXLEN 300
int direct[MAX_DIRECT][MAX_DIRECT] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int vist[MAXLEN][MAXLEN];
bool isNextValid(int** grid, int i, int j, int direction, int gridSize, int gridColSize)
{
    int nextX = i + direct[direction - 1][0];
    int nextY = j + direct[direction - 1][1];
    if (nextX < 0 || nextX >= gridSize || nextY < 0 || nextY >= gridColSize) {
        return false;  
    }
    // 向上
    if (direction == 1) {
        if ((grid[i][j] == 2 || grid[i][j] == 5 || grid[i][j] == 6) && 
           (grid[nextX][nextY] == 2 || grid[nextX][nextY] == 3 || grid[nextX][nextY] == 4)) {
            return true;
        }
        return false;
    }
    // 向下
    if (direction == 2) {
        if ((grid[i][j] == 2 || grid[i][j] == 3 || grid[i][j] == 4) && 
           (grid[nextX][nextY] == 2 || grid[nextX][nextY] == 5 || grid[nextX][nextY] == 6)) {
            return true;
        }
        return false;
    }
    // 向右
    if (direction == 3) {
        if ((grid[i][j] == 1 || grid[i][j] == 4 || grid[i][j] == 6) && 
           (grid[nextX][nextY] == 1 || grid[nextX][nextY] == 3 || grid[nextX][nextY] == 5)) {
            return true;
        }
        return false;
    }
    // 向左
    if (direction == 4) {
        if ((grid[i][j] == 1 || grid[i][j] == 3  || grid[i][j] == 5 ) && 
           (grid[nextX][nextY] == 1 || grid[nextX][nextY] == 4 || grid[nextX][nextY] == 6)) {
            return true;
        }
        return false;
    }
    return false;
}

bool Dfs(int** grid, int gridSize, int x, int y, int* gridColSize)
{
    if (x == gridSize -1 && y == gridColSize[0] - 1) {
        return true;
    }
    for (int i = 1; i <= 4; i++) {
        int nextX = x + direct[i - 1][0];
        int nextY = y + direct[i - 1][1];        
        if (isNextValid(grid, x, y, i, gridSize, gridColSize[0])) {
            if (vist[nextX][nextY] == 0) {
                vist[nextX][nextY] = 1;                
                bool check = Dfs(grid, gridSize, nextX, nextY, gridColSize);
                if (check) {
                    return true;
                }
                vist[nextX][nextY] = 0;             
            }
        }
    }
    return false;
}
bool hasValidPath(int** grid, int gridSize, int* gridColSize){
    if (gridSize == 0 || grid == NULL) {
        return false;
    }
    memset(vist, 0 , sizeof(int) * MAXLEN * MAXLEN);
    vist[0][0] = 1;
    return Dfs(grid, gridSize, 0, 0, gridColSize);
}