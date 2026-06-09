### 解题思路
此处撰写解题思路

### 代码

```c
void dfs(int **M, int MSize, int cur, int *visited)
{
    for(int i = 0; i < MSize; i++) {
        if (M[cur][i] == 1 && visited[i] == 0) {
            visited[i] = 1;
            dfs(M, MSize, i, visited);
        }
    }
}

int findCircleNum(int** M, int MSize, int* MColSize)
{
    // 思路，图的数据结构，如果 M[i][j] = 1, 则 i-j相连
    // 按照深度优先算法进行搜索，并标记已搜索节点
    // 计算全部搜索完，总共有几个连通图
    // 简化: 因为矩阵是对称的，所以只需要搜索上半部分。

    int count = 0;
    int *visited = (int *)calloc(MSize, sizeof(int));

    for (int i = 0; i < MSize; i++) {
        if (visited[i] == 0) {
            dfs(M, MSize, i, visited);
            count++;
        }
    }
    free(visited);
    *MColSize = count;
    return count;
}
```