### 解题思路
算法是DFS，没什么说的，从0,0开始，找到m-1,n-1就退出，主要差异点在判断路径是否可以走通，定义了一个二维数组，保存每个方块上下左右能够联通的信息，判断函数传入上个点，下个点，以及走的方向，举个例子，如果上个点可以向左右走，走的方向是往左，那么下个点必然需要可以往右走才能联通

### 代码

```c
#define MAXNUM 300
#define MAXCUBE 6
#define MAXDIR 4

// 定义DFS要走的方向，顺序也是左右上下，和下面数组的顺序对应
const g_dir[MAXDIR][2] = {
    {0, -1},
    {0, 1},
    {-1, 0},
    {1, 0}
};

// 数组记录每个块可以连接的方向，顺序分别是左右上下
const g_list[MAXCUBE][MAXDIR] = {
    {1, 1, 0, 0},
    {0, 0, 1, 1},
    {1, 0, 0, 1},
    {0, 1, 0, 1},
    {1, 0, 1, 0},
    {0, 1, 1, 0},
};

int g_visit[MAXNUM][MAXNUM] = {{0}};
int g_maxx = 0;
int g_maxy = 0;
bool g_check = false;

bool checkvalid(int now, int next, int dir)
{
    if ((now > MAXCUBE) || (next > MAXCUBE) || (dir >= MAXDIR)) {
        return false;
    }
    // 首先计算要去的下一个点的方向
    int dirtmp = (dir < 2) ? (1 - dir) : (5 - dir);
    // 判断两个点的方向是否能够连接
    if ((g_list[now - 1][dir] != 0) && (g_list[next - 1][dirtmp] == g_list[now - 1][dir])) {
        return true;
    }

    return false;
}

void dfs(int **grid, int x, int y)
{
    int nx;
    int ny;

    if ((x == g_maxx - 1) && (y == g_maxy - 1)) {
        g_check = true;
        return;
    }

    for (int i = 0; i < MAXDIR; i++) {
        nx = x + g_dir[i][0];
        ny = y + g_dir[i][1];
        if ((nx >= 0) && (nx < g_maxx) && (ny >= 0) && (ny < g_maxy) && (g_visit[nx][ny] == 0) &&
            checkvalid(grid[x][y], grid[nx][ny], i)) {
            g_visit[nx][ny] = 1;
            dfs(grid, nx, ny);
            if (g_check) {
                return;
            }
            g_visit[nx][ny] = 0;
        }
    }
}

bool hasValidPath(int **grid, int gridSize, int *gridColSize)
{
    if ((grid == NULL) || (gridSize == 0) || (gridColSize == NULL) || (gridColSize[0] == NULL)) {
        return false;
    }

    g_maxx = gridSize;
    g_maxy = gridColSize[0];

    for (int i = 0; i < MAXNUM; i++) {
        for (int j = 0; j < MAXNUM; j++) {
            g_visit[i][j] = 0;
        }
    }

    g_check = false;

    g_visit[0][0] = 1;
    dfs(grid, 0, 0);

    return g_check;
}
```