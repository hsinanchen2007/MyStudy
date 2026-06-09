### 解题思路
套用DFS大法，其中，类似树的遍历，需要沿一个分支遍历到头，即遇到墙，才改变方向，与岛屿的题目不同，遍历时每个节点需要记住上次遍历的方向。
而终点判断条件，也不是简单的到达目的地，还要判断在到达目的地的方向上，相邻的点是否是墙
![image.png](https://pic.leetcode-cn.com/a086361a3050bb32b97b343be3808f59fc500e68506f865213c7aa68cc3eb5ca-image.png)

### 代码

```c
#define MAX_SIZE    100
typedef struct tagPos {
    int row;
    int col;
    int dir; /* 方向 */
} Pos;

int g_direct[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool IsInvalid(Pos *step, Pos *max)
{
    if ((step->row < 0) || (step->col < 0) || (step->row >= max->row) || (step->col >= max->col)) {
        return true;
    }

    return false;
}

bool IsNextWall(int **maze, Pos *step, Pos *dst, Pos *max)
{
    Pos next = {
        .row = step->row + g_direct[step->dir][0],
        .col = step->col + g_direct[step->dir][1],
        .dir = step->dir
    };

    /* 边界也是墙 */
    if (IsInvalid(&next, max) == true) {
        return true;
    }

    /* 遇到墙 */
    if (maze[next.row][next.col] == 1) {
        return true;
    }

    return false;
}

bool IsArriveDst(int **maze, Pos *step, Pos *dst, Pos *max)
{
    /* 到达终点且这个方向上有墙 */
    if ((step->row == dst->row) && (step->col == dst->col) && 
        (IsNextWall(maze, step, dst, max))) {
        return true;
    }

    return false;
}

void GetNextPos(int **maze, Pos *step, Pos *max, Pos *next)
{
    Pos nextTpm = {
        .row = step->row + g_direct[step->dir][0],
        .col = step->col + g_direct[step->dir][1],
        .dir = step->dir
    };

    while (IsInvalid(&nextTpm, max) != true && (maze[nextTpm.row][nextTpm.col] == 0)) {
        nextTpm.row = nextTpm.row + g_direct[step->dir][0];
        nextTpm.col = nextTpm.col + g_direct[step->dir][1];
    }

    next->row = nextTpm.row - g_direct[step->dir][0];
    next->col = nextTpm.col - g_direct[step->dir][1];
    next->dir = step->dir;

    return;
}

bool Dfs(int **maze, Pos *step, Pos *dst, Pos *max, int **visited)
{
    /* 判断是否到达终点 */
    if (IsArriveDst(maze, step, dst, max) == true) {
        return true;
    }

    /* 边界判断 */
    if (IsInvalid(step, max) == true) {
        return false;
    }

    if (maze[step->row][step->col] == 1) {
        return false;
    }

    if (visited[step->row][step->col] != 0) {
        return false;
    }

    visited[step->row][step->col] = 1;
    for (int i = 0; i < 4; i++) {
        Pos next;
        step->dir = i;
        /* 获取下一个点位置，前提先沿一个方向到墙 */
        GetNextPos(maze, step, max, &next);

        if (Dfs(maze, &next, dst, max, visited) == true) {
            return true;
        }
    }

    return false;
}

bool hasPath(int** maze, int mazeSize, int* mazeColSize, int* start, int startSize, int* destination, int destinationSize){
    /* 入参判断 */
    bool invalid = (maze == NULL) || (mazeSize == 0) || (mazeColSize == NULL) || (start == NULL) || (startSize <= 1) || (destination == NULL) || (destinationSize <= 1);
    if (invalid == true) {
        return false;
    }
    Pos src = {
        .row = start[0],
        .col = start[1],
        .dir = 0
    };
    Pos dst = {
        .row = destination[0],
        .col = destination[1],
        .dir = 0
    };
    Pos max = {
        .row = mazeSize,
        .col = *mazeColSize,
        .dir = 0
    };

    /* 入参判断 */
    if ((maze[src.row][src.col] == 1) || (maze[dst.row][dst.col] == 1)) {
        return false;
    }

    int **visited = (int **)malloc(sizeof(int *) * max.row);
    for (int i = 0; i < max.row; i++) {
        visited[i] = malloc(sizeof(int) * max.col);
        memset(visited[i], 0, sizeof(int) * max.col);
    }
    
    bool ret = Dfs(maze, &src, &dst, &max, visited);

    for (int i = 0; i < max.row; i++) {
        free(visited[i]);
    }
    free(visited);
    return ret;
}
```