int *g_visited = NULL;
int g_size;
void dfs(int** M, int j)
{
    for (int i = 0; i < g_size; i++) {
        if (M[i][j] == 1 && g_visited[i] == 0) {
            g_visited[i] = 1;
            dfs(M, i);
        }
    }
}

int findCircleNum(int** M, int MSize, int* MColSize)
{
    int count = 0;
    g_visited = malloc(sizeof(int) * MSize);
    memset(g_visited, 0, sizeof(int) * MSize);
    g_size = MSize;
    for (int i = 0; i < MSize; i++) {
        if (g_visited[i] == 0) {
           dfs(M, i);
           count++;
        }
    }
    return count;
}