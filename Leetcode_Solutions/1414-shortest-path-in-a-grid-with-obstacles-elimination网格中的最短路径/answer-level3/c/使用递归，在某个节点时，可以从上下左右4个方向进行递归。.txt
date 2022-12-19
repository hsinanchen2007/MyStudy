### 解题思路
此处撰写解题思路

### 代码

```c
#define INF 2147483647
#define MAX_MN_VAL 40

int g_engX = 0;
int g_engY = 0;

int g_minStepNum = INF;
int g_grid[MAX_MN_VAL][MAX_MN_VAL] = {0};
int g_gridVisitFlag[MAX_MN_VAL][MAX_MN_VAL] = {0};

void BFSUp(int beginX, int beginY, int k, int stepNum);
void BFSDown(int beginX, int beginY, int k, int stepNum);
void BFSLeft(int beginX, int beginY, int k, int stepNum);
void BFSRight(int beginX, int beginY, int k, int stepNum);
void BFS(int beginX, int beginY, int k, int stepNum);

int IsNextStepObj(int x, int y)
{
    if (x + 1 == g_engX && y == g_engY) {
        return 1;
    }

    if (x - 1 == g_engX && y == g_engY) {
        return 1;
    }

    if (x == g_engX && y - 1 == g_engY) {
        return 1;
    }

    if (x == g_engX && y + 1 == g_engY) {
        return 1;
    }

    return 0;
}

void BFSUp(int beginX, int beginY, int k, int stepNum)
{
    if (beginX - 1 >= 0) {
        if (g_grid[beginX - 1][beginY] == 0) {
            BFS(beginX - 1, beginY, k, stepNum + 1);
        } else {
            if (k >= 1) {
                BFS(beginX - 1, beginY, k - 1, stepNum + 1);
            } else {
                return;
            }
        }
    }
    return;
}

void BFSRight(int beginX, int beginY, int k, int stepNum)
{
    if (beginY + 1 <= g_engY) {
        if (g_grid[beginX][beginY + 1] == 0) {
            BFS(beginX, beginY + 1, k, stepNum + 1);
        } else {
            if (k >= 1) {
                BFS(beginX, beginY + 1, k - 1, stepNum + 1);
            } else {
                return;
            }
        }
    }
    return;
}

void BFSLeft(int beginX, int beginY, int k, int stepNum)
{
    if (beginY - 1 >= 0) {
        if (g_grid[beginX][beginY - 1] == 0) {
            BFS(beginX, beginY - 1, k, stepNum + 1);
        } else {
            if (k >= 1) {
                BFS(beginX, beginY - 1, k - 1, stepNum + 1);
            } else {
                return;
            }
        }
    }
    return;
}

void BFSDown(int beginX, int beginY, int k, int stepNum)
{
    if (beginX + 1 <= g_engX) {
        if (g_grid[beginX + 1][beginY] == 0) {
            BFS(beginX + 1, beginY, k, stepNum + 1);
        } else {
            if (k >= 1) {
                BFS(beginX + 1, beginY, k - 1, stepNum + 1);
            } else {
                return;
            }
        }
    }
    return;
}


void BFS(int beginX, int beginY, int k, int stepNum)
{
    //减支处理
    if (g_minStepNum <= g_engX + g_engY || g_gridVisitFlag[beginX][beginY] == 1) {
        return;
    }

    //标记该节点访问过，不需要再继续递归
    if (g_gridVisitFlag[beginX][beginY] == 1) {
        return;
    }

    //考虑源点和目标点是同一个点时候时，迭代退出条件
    if (beginX == g_engX && beginY == g_engY) {
        g_minStepNum = 0;
        return;
    }

    //递归退出条件
    if (IsNextStepObj(beginX, beginY) == 1) {
        if (g_minStepNum > stepNum + 1) {
            g_minStepNum = stepNum + 1;
        }        
        return; 
    }

    //标记本轮该节点被访问过，同时避免两个点之间乒乓迭代
    g_gridVisitFlag[beginX][beginY] = 1;

    //按照上下行左右4个方向去尝试遍历
    BFSDown(beginX, beginY, k, stepNum);
    BFSRight(beginX, beginY, k, stepNum);
    BFSUp(beginX, beginY, k, stepNum);
    BFSLeft(beginX, beginY, k, stepNum);

    //标记还原原因：某个节点因为错误尝试路径，别的路径可能会继续使用该节点，需要将表示还原
    g_gridVisitFlag[beginX][beginY] = 0;
}

int GetResult()
{
    if(g_minStepNum != INF) {
        return g_minStepNum;
    } else {
        return -1;
    }

}

//力扣题目每次都先初始化相关的变量，避免残留影响
void InitVar(int **grid, int m, int n)
{
    g_engX = m - 1;
    g_engY = n - 1;
    g_minStepNum = INF;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            g_grid[i][j] =  grid[i][j];
            g_gridVisitFlag[i][j] = 0;
        }
    }
}

int shortestPath(int **grid, int gridSize, int* gridColSize, int k)
{
    int beginX = 0;
    int beginY = 0;

    InitVar(grid, gridSize, *gridColSize);

    BFS(beginX, beginY, k, 0);

    return GetResult();
}
```