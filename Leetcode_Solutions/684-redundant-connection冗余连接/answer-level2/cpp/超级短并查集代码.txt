```
int f[1010];
int find(int x)
{
    return x == f[x] ? x : (f[x] = find(f[x]));
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    *returnSize = 2;
    int u, v, i;
    int *res = (int *) malloc(sizeof(int) * 2);
    for (i = 1; i <= edgesSize; i++) f[i] = i;
    for (i = 0; i < edgesSize; i++) {
        u = edges[i][0];
        v = edges[i][1];
        if (find(u) != find(v)) {
            f[find(u)] = find(v); 
        } else {
            res[0] = u, res[1] = v;
            break;
        }
    }
    return res;
}
```
