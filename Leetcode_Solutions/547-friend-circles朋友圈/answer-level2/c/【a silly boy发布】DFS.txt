![78BE3CE3-601F-4058-B75A-2FE900F1FCEE.jpeg](https://pic.leetcode-cn.com/edd4ab918668939304010ed31ee3c73bff45a28fdd81fe065be81477f8fcc21f-78BE3CE3-601F-4058-B75A-2FE900F1FCEE.jpeg)

```
void SubFucDFS(int** M, int MSize, int* MColSize, int index, int *visited) {
    int i;
    visited[index] = 1;
    for (i = 0; i < MSize; i++) {
        if ((M[index][i] == 1) && (visited[i] == 0)){
            SubFucDFS(M, MSize, MColSize, i, visited);
        }
    }
}

int findCircleNum(int** M, int MSize, int* MColSize){
    if ((M == NULL) || (MSize == 0) || (MColSize == NULL) || (*MColSize == 0)) {
        return 0;
    }
    int i;
    int returnValue = 0;
    int *visited = (int *)malloc(MSize * sizeof(int));
    memset(visited, 0, MSize * sizeof(int));

    for (i = 0; i < MSize; i++) {
        if (visited[i] == 0) {
            SubFucDFS(M, MSize, MColSize, i, visited);
            returnValue++;
        }
    }

    return returnValue;
}
```
