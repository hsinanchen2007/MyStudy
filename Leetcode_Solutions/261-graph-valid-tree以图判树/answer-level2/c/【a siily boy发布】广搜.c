```
bool SubFunc(int** edges, int edgesSize, int* edgesColSize, int *flag, int index, int *visited) {
    int i = 0;
    bool returnValue = true;
    if (flag[index] == true) {
        return false;
    }
    flag[index] = true;
    for (i = 0; i < edgesSize; i++) {
        if ((edges[i][0] == index) && (visited[i] == 0)) {
            visited[i] = 1;
            returnValue = SubFunc(edges, edgesSize, edgesColSize, flag, edges[i][1], visited);
        }
        if ((edges[i][1] == index) && (visited[i] == 0)) {
            visited[i] = 1;
            returnValue = SubFunc(edges, edgesSize, edgesColSize, flag, edges[i][0], visited);
        }
        if (returnValue == false) {
            return false;
        } 
    }

    return returnValue;
}

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

bool validTree(int n, int** edges, int edgesSize, int* edgesColSize){
    if (n == 1) {
        return true;
    }
    if ((n == 0) || (edges == NULL) || (edgesSize == 0) || (edgesColSize == NULL)) {
        return false;
    }
    bool returnValue = true;
    int index = 0;
    int i;
    int j;
    int *flag = (int *)malloc(n * sizeof(int));
    int *visited = (int *)malloc(edgesSize * sizeof(int));
    memset(flag, 0, n * sizeof(int));
    memset(visited, 0, edgesSize * sizeof(int));
    
    index = edges[0][0];
    returnValue = SubFunc(edges, edgesSize, edgesColSize, flag, index, visited);
    for (i = 0; i < n; i++) {
        if (flag[i] == 0) {
            return false;
        }
    }
    return returnValue;
}
```
