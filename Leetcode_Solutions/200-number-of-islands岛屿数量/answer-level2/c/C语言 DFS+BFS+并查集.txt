只学过C，所以只能用C写了。
我真的太难了……


DFS
```
typedef struct {
    int i, j;
} Vertex;
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
    Vertex e, *stack = (Vertex*)malloc(sizeof(Vertex) * n * m);
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
    for (i = 0; i < gridSize; i++)
        free(visited[i]);
    free(visited);
    return count;
}
```

BFS
```
typedef struct {
    int i, j;
} Vertex;
void BFS(char** grid, int i, int j, int n, int m, int** visited) {
    int front = -1, rear = -1;
    Vertex tmp, *Qu = (Vertex*)malloc(sizeof(Vertex) * n * m);
    visited[i][j] = 1;
    tmp.i = i;
    tmp.j = j;
    Qu[++rear] = tmp;
    while (front != rear) {
        tmp = Qu[++front];
        i = tmp.i;
        j = tmp.j;
        if (i + 1 < n && grid[i + 1][j] == '1' && visited[i + 1][j] == 0) {
            visited[i + 1][j] = 1;
            tmp.i = i + 1;
            tmp.j = j;
            Qu[++rear] = tmp;
        }
        if (j - 1 >= 0 && grid[i][j - 1] == '1' && visited[i][j - 1] == 0) {
            visited[i][j - 1] = 1;
            tmp.i = i;
            tmp.j = j - 1;
            Qu[++rear] = tmp;
        }
        if (i - 1 >= 0 && grid[i - 1][j] == '1' && visited[i - 1][j] == 0) {
            visited[i - 1][j] = 1;
            tmp.i = i - 1;
            tmp.j = j;
            Qu[++rear] = tmp;
        }
        if (j + 1 < m && grid[i][j + 1] == '1' && visited[i][j + 1] == 0) {
            visited[i][j + 1] = 1;
            tmp.i = i;
            tmp.j = j + 1;
            Qu[++rear] = tmp;
        }
    }
    free(Qu);
}
int numIslands(char** grid, int gridSize, int* gridColSize) {
    int i, j, count = 0;
    int** visited = (int**)malloc(sizeof(int*) * gridSize);
    for (i = 0; i < gridSize; i++)
        visited[i] = (int*)malloc(sizeof(int) * (*gridColSize));
    for (i = 0; i < gridSize; i++)
        for (j = 0; j < *gridColSize; j++)
            visited[i][j] = 0;
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == '1' && visited[i][j] == 0) {
                BFS(grid, i, j, gridSize, *gridColSize, visited);
                count++;
            }
        }
    }
    for (i = 0; i < gridSize; i++)
        free(visited[i]);
    free(visited);
    return count;
}
```

并查集
```
typedef struct {
    int data;
    int father;
    int rank;
} UFSTree;
void MAKE_SET(UFSTree* t, int n, char** grid, int gridSize, int* gridColSize) {
    int i, j, k;
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < (*gridColSize); j++) {
            k = i * (*gridColSize) + j;
            if (grid[i][j] == '1') {
                t[k].data = k;
                t[k].father = k;
                t[k].rank = 0;
            } else
                t[k].father = -1;
        }
    }
}
int FIND_SET(UFSTree* t, int x) {
    while (t[x].father != x) {
        x = t[x].father;
    }
    return x;
}
void UNION(UFSTree* t, int x, int y, int* count) {
    x = FIND_SET(t, x);
    y = FIND_SET(t, y);
    if (x >= 0 && y >= 0 && x != y) {
        if (t[x].rank < t[y].rank) {
            t[x].father = y;
        } else {
            t[y].father = x;
            if (t[x].rank == t[y].rank)
                t[x].rank++;
        }
        (*count)--;
    }
}
int numIslands(char** grid, int gridSize, int* gridColSize) {
    if(gridSize == 0)
        return 0;
    int i, j, k1, k2, n = gridSize * (*gridColSize), count = n;
    UFSTree* t = (UFSTree*)malloc(sizeof(UFSTree) * n);
    MAKE_SET(t, n, grid, gridSize, gridColSize);
    for (i = 0; i < gridSize; i++) {
        for (j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == '1') {
                k1 = i * (*gridColSize) + j;
                if (i + 1 < gridSize && grid[i + 1][j] == '1') {
                    k2 = k1 + (*gridColSize);
                    UNION(t, k1, k2, &count);
                    //count是否自减，必须通过UNION函数才能确定，因为有可能k1和k2是同一个树根
                }
                if (j + 1 < *gridColSize && grid[i][j + 1] == '1') {
                    k2 = k1 + 1;
                    UNION(t, k1, k2, &count);
                }
            } else
                count--;
        }
    }
    free(t);
    return count;
}
```


