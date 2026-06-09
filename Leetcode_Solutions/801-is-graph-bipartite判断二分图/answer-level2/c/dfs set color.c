```
bool dfs(int **graph, int size, int *col, int *color, int start,  int set)
{
    for (int j = 0; j < col[start]; j++) {
        int i = graph[start][j];
        if (color[i] == 0) {
            color[i] = set == 1 ? 2 : 1;
            if (dfs(graph, size, col, color, i, color[i]) == false) {
                return false;
            }
        } else {
            if (color[i] == set) {
                return false;
            }
        }
    }

    return true;
}

bool isBipartite(int** graph, int graphSize, int* graphColSize)
{
    int *color = malloc(sizeof(int) * graphSize);
    memset(color, 0, sizeof(int) * graphSize);

    for (int i = 0; i < graphSize; i++) {
        if (color[i] == 0) {
            color[i] = 1;
            if (dfs(graph, graphSize, graphColSize, color, i, 1) == false) {
                return false;
            }
        }
    }

    return true;
}
```
