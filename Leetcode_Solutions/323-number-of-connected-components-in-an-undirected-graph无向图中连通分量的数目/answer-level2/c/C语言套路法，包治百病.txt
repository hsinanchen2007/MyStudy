![image.png](https://pic.leetcode-cn.com/ce2f6b98b6673998d74bea6bc20ce88fe65a5f5286bff9ee58b8f37d0d4d3cff-image.png)
```
int UnionFindSetsFind(int *pre, int x)
{
    int r = x;
    while (pre[r] != r) {
        r = pre[r];
    }
    int i = x;
    int j;
    while (i != r) {
        j = pre[i];
        pre[i] = r;
        i = j;
    }
    return r;
}
void UnionFindSetsJoin(int *pre, int x, int y, int *rst)
{
    int fx = UnionFindSetsFind(pre, x);
    int fy = UnionFindSetsFind(pre, y);
    if (fx != fy) {
        pre[fy] = fx;
        (*rst)--;
    }
}
void UnionFindSetsInit(int *pre, int size)
{
    for (int i = 0; i < size; i++) {
        pre[i] = i;
    }
}
int countComponents(int n, int** edges, int edgesSize, int* edgesColSize){
    int *pre = (int*)calloc(n+1, sizeof(int));
    int m = edgesSize;
    //int n = edgesColSize[0];
    UnionFindSetsInit(pre, n+1);
    int rst = n;
    for (int i = 0; i < m; i++) {
        UnionFindSetsJoin(pre, edges[i][0], edges[i][1], &rst);
    }
    free(pre);
    return rst;
}
```
