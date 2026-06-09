```
int g_dis[101][101];
void InitDis(int **edges, int edgesSize)
{
    int i, j, k;
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            g_dis[i][j] = 1000000;
        }
        g_dis[i][i] = 0;
    }
    for (k = 0; k < edgesSize; k++) {
        g_dis[edges[k][0]][edges[k][1]] = edges[k][2];
        g_dis[edges[k][1]][edges[k][0]] = edges[k][2];
    }
}
void Floyd(int n)
{
    int i, j, k;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (g_dis[i][j] > g_dis[i][k] + g_dis[k][j]) {
                    g_dis[i][j] = g_dis[i][k] + g_dis[k][j];
                }
            }
        }
    }
}
int findTheCity(int n, int** edges, int edgesSize, int* edgesColSize, int distanceThreshold){
    int *set = calloc(n, sizeof(int));
    int min, i, j, k;
    InitDis(edges, edgesSize);
    Floyd(n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if ((i != j) && (g_dis[i][j] <= distanceThreshold)) {
                set[i]++;
            }   
        }   
    }
    min = 0;
    for (k = 0; k < n; k++) {
        if (set[min] >= set[k]) {
            min = k;
        }
    }
    free(set);
    return min;
}
```
