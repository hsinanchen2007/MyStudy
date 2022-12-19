```
typedef struct {
    int i, j;
} Node;
void DFS(char** g, int i, int j, int n, int m, int** visited) {
    //递归
    // if (g[i][j] == '0')
    //     return;
    // visited[i][j] = 1;
    // if (i + 1 < n && visited[i + 1][j] == 0)
    //     DFS(g, i + 1, j, n, m, visited);
    // if (j - 1 >= 0 && visited[i][j - 1] == 0)
    //     DFS(g, i, j - 1, n, m, visited);
    // if (i - 1 >= 0 && visited[i - 1][j] == 0)
    //     DFS(g, i - 1, j, n, m, visited);
    // if (j + 1 < m && visited[i][j + 1] == 0)
    //     DFS(g, i, j + 1, n, m, visited);

    //迭代
    Node e, *stack = (Node*)malloc(sizeof(Node) * n * m);
    int top = -1;
    bool find;
    visited[i][j] = 1;
    e.i = i;
    e.j = j;
    stack[++top] = e;
    while (top != -1) {
        e = stack[top];
        i = e.i;
        j = e.j;
        find = false;
        if (i + 1 < n && g[i + 1][j] == '1' && visited[i + 1][j] == 0) {
            e.i = i + 1;
            e.j = j;
            visited[e.i][e.j] = 1;
            stack[++top] = e;
            continue;
        }
        if (j - 1 >= 0 && g[i][j - 1] == '1' && visited[i][j - 1] == 0) {
            e.i = i;
            e.j = j - 1;
            visited[e.i][e.j] = 1;
            stack[++top] = e;
            continue;
        }
        if (i - 1 >= 0 && g[i - 1][j] == '1' && visited[i - 1][j] == 0) {
            e.i = i - 1;
            e.j = j;
            visited[e.i][e.j] = 1;
            stack[++top] = e;
            continue;
        }
        if (j + 1 < m && g[i][j + 1] == '1' && visited[i][j + 1] == 0) {
            e.i = i;
            e.j = j + 1;
            visited[e.i][e.j] = 1;
            stack[++top] = e;
            continue;
        }
        top--;
    }
    free(stack);
}
int numIslands(char** grid, int gridSize, int* gridColSize) {
    int i, j, count = 0;
    //初始化visited数组
    int** visited = (int**)malloc(sizeof(int*) * gridSize);
    for (i = 0; i < gridSize; i++)
        visited[i] = (int*)malloc(sizeof(int) * gridColSize[i]);
    for (i = 0; i < gridSize; i++)
        for (j = 0; j < gridColSize[i]; j++)
            visited[i][j] = 0;
    //深度优先搜索,为了标记相邻的所有陆地
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == '1' && visited[i][j] == 0) {
                DFS(grid, i, j, gridSize, *gridColSize, visited);
                count++;
            }
        }
    }
    free(visited);
    return count;
}
```
