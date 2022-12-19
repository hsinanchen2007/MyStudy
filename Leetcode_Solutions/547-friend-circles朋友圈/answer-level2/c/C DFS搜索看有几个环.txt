### 解题思路
DFS搜索，记录下搜索的环数目

### 代码

```c
#define MAXNUM 201
int visited[201];
int MaxRow = 0;
int MaxCol = 0;

void dfs(int **M, int x)
{
    int k = 0;
    for (k = 0; k < MaxCol; k++) {
        if (visited[k] == 0 && M[x][k] == 1) {
            visited[k] = 1;
            dfs(M, k);
        }
    }
}
int findCircleNum(int** M, int MSize, int* MColSize){
    int circules = 0;
    int i = 0;
    MaxRow = MSize;
    MaxCol = *MColSize;
    memset(visited, 0, sizeof(int) * MAXNUM);
    for (i = 0; i < MaxRow; i++) {
        if (visited[i] == 0) {
            dfs(M, i);
            circules++;
        }
    }
    return circules;
}
```