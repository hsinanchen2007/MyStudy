// DFS 算法
// 1. 邻接矩阵代表关系
// 2. DFS: 一个节点为起点遍历，如果还有unVisited，则再使用一个unVisited节点遍历。直到所有的节点都被遍历到。

void Dfs(int **M, int i, int MSize, bool *visited)
{
    visited[i] = true;
    for (int j = 0; j < MSize; j++) {
        if (M[i][j] != 0 && (!visited[j])) {
            Dfs(M, j, MSize, visited);
        }
    }
    return;
}

int findCircleNum(int** M, int MSize, int* MColSize){
    int circleNum = 0;
    bool *visited = malloc(MSize * sizeof(bool));
    if (visited == NULL) {
        return MSize;
    }
    memset(visited, 0, MSize * sizeof(bool)) ;
    for (int i = 0; i < MSize; i++) {
        if (!visited[i]) {            
            Dfs(M, i, MSize, visited);
            circleNum++;
        }
    }

    free(visited);
    return circleNum;
}