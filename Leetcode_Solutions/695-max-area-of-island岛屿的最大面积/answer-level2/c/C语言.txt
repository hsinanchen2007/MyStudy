### 解题思路
此处撰写解题思路

### 代码
深搜+递归
int dfs(int** grid, int gridSize, int* gridColSize, int i, int j) {
    if (i < 0 || j < 0 || i == gridSize || j == *gridColSize || grid[i][j] == 0) {
        return 0;
    }
    grid[i][j] = 0;
    int ans = 1;
    int x[4] = {0, -1, 0, 1};
    int y[4] = {-1, 0, 1, 0};
    for (int k = 0; k < 4; ++k) {
        ans += dfs(grid, gridSize, gridColSize, i + x[k], j + y[k]);
    }
    return ans;
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int ans = 0;
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < *gridColSize; ++j) {
            int t = dfs(grid, gridSize, gridColSize, i, j);
            ans = ans > t ? ans : t;
        }
    }
    return ans;
}

深搜+栈
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int stack[5000][2];
    int p = -1; // 栈顶指针
    int ans = 0;

    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < *gridColSize; ++j) {
            int t = 0;
            stack[++p][0] = i;
            stack[p][1] = j; 
            while (p > -1) {
                int row = stack[p][0];
                int col = stack[p][1];
                p--;
                if (row < 0 || col < 0 || row == gridSize || col == *gridColSize || grid[row][col] == 0) {
                    continue;
                }
                grid[row][col] = 0;
                t++;
                int x[4] = {-1, 0, 1, 0};
                int y[4] = {0, 1, 0, -1};
                for (int k = 0; k < 4; ++k) {
                    stack[++p][0] = row + x[k];
                    stack[p][1] = col + y[k];
                }
            }
            ans = ans > t ? ans : t;
        }
    }
    return ans;
}
广搜
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int stack[20000][2];
    int ans = 0;

    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < *gridColSize; ++j) {

            int t = 0, ph = -1, pt = -1; // ph队列头指针，pt队尾指针

            stack[++pt][0] = i;
            stack[pt][1] = j; 
            while (ph != pt) {
                int row = stack[++ph][0];
                int col = stack[ph][1];
                if (row < 0 || col < 0 || row == gridSize || col == *gridColSize || grid[row][col] == 0) {
                    continue;
                }
                grid[row][col] = 0;
                t++;
                int x[4] = {-1, 0, 1, 0};
                int y[4] = {0, 1, 0, -1};
                for (int k = 0; k < 4; ++k) {
                    stack[++pt][0] = row + x[k];
                    stack[pt][1] = col + y[k];
                }
            }
            ans = ans > t ? ans : t;
        }
    }
    return ans;
}


```