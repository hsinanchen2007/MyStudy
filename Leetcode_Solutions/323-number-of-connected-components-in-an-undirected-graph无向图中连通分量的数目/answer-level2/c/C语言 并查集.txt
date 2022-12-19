
```
int *g_fater = 0;

int find(int x)
{
    int r = x;

    while (g_fater[r] != r) {
        r = g_fater[r];
    }

    /* 压缩路径 */
    int i = x;
    int j;
    while (i != r) {
        j = g_fater[i];
        g_fater[i] = r;
        i = j;
    }

    return r;
}

void joint(int x, int y)
{
    int fx = find(x);
    int fy = find(y);

    if (fx != fy) {
        g_fater[fx] = fy;
    }
}

int countComponents(int n, int** edges, int edgesSize, int* edgesColSize){

    if (n < 2) {
        return n;
    }

    g_fater = (int *)malloc(n * sizeof(int));
    if (g_fater == NULL) {
        return -1;
    }

    /* 初始化 */
    for (int i = 0; i < n; i++) {
        g_fater[i] = i;
    }

    for (int i = 0; i < edgesSize; i++) {
        joint(edges[i][0], edges[i][1]);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (g_fater[i] == i) {
            cnt++;
        }
    }

    return cnt;
}
```
