![image.png](https://pic.leetcode-cn.com/5c8d1ed25cac46c5a196ed947a6801e81f1f7ad5c50bd80ccff40f1ed70d9a8d-image.png)

```c
#define HASH_SIZE 100005

int cmp(const void *a, const void *b) {
    int **aa = (int**)a;
    int **bb = (int**)b;
    if ((*aa)[0] == (*bb)[0]) {
        return (*aa)[1] - (*bb)[1];
    }
    return (*aa)[0] - (*bb)[0];
}

int g_vis[HASH_SIZE];

int FindFirstBiggerThan(int x, int **connections, int row) {
    int left = 0;
    int right = row - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (connections[mid][0] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        } 
    }
    return left;
}

void dfs(int x, int** connections, int** copyConnections, int row) {
    if (g_vis[x]) {
        return ;
    }
    g_vis[x] = true;
    int i = FindFirstBiggerThan(x, connections, row);
    for (; i < row && connections[i][0] == x; ++i) {
        dfs(connections[i][1], connections, copyConnections, row);
    }

    i = FindFirstBiggerThan(x, copyConnections, row);
    for (; i < row && copyConnections[i][0] == x; ++i) {
        dfs(copyConnections[i][1], connections, copyConnections, row);
    }
}

int makeConnected(int n, int** connections, int connectionsSize, int* connectionsColSize){
    if (connectionsSize < n - 1) {
        return -1;
    }
    if (n > 0 && (connections == NULL || connectionsColSize == NULL || connectionsSize == 0)) {
        return -1;
    }
    int row = connectionsSize;
    int col = connectionsColSize[0];
    int ret = -1;
    memset(&g_vis, false, sizeof(g_vis));
    int **copyConnections = (int**)malloc(sizeof(int*) * row);
    for (int i = 0; i < row; ++i) {
        copyConnections[i] = (int*)malloc(sizeof(int) * col);
        memcpy(copyConnections[i], connections[i], sizeof(int) * col);
        copyConnections[i][0] ^= copyConnections[i][1];
        copyConnections[i][1] ^= copyConnections[i][0];
        copyConnections[i][0] ^= copyConnections[i][1];
    }
    qsort(connections, row, sizeof(int) * col, cmp);
    qsort(copyConnections, row, sizeof(int) * col, cmp);

    
    for (int i = 0; i < n; ++i)
    {
        if (!g_vis[i]) {
            dfs(i, connections, copyConnections, row);
            ++ret;
        }
    }
    return ret;
}
```