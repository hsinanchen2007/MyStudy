```
int FindRoot(const int *uf, int index) 
{
    while (uf[index] != index) {
        index = uf[index];
    }
    return index;
}

bool Union(int *uf, int x, int y) 
{
    int rootX = FindRoot(uf, x);
    int rootY = FindRoot(uf, y);
    if (rootX == rootY) {
        return false;
    } else {
        uf[rootY] = rootX;
        return true;
    }
}
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize)
{   
    if (edgesSize == 0 || (edgesSize != 0 && edgesColSize[0] == 0)) {
        *returnSize = 0;
        return NULL;
    }
    int n = edgesSize + 1;
    int uf[n];
    for (int i = 1; i < n; i++) {
        uf[i] = i;
    }
    *returnSize = edgesColSize[0];
    for (int i = 0; i < edgesSize; i++) {
        if (Union(uf, edges[i][0], edges[i][1]) == false) {
            return edges[i];
        }
    }
    return NULL;
}
```
