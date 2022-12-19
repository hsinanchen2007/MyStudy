![image.png](https://pic.leetcode-cn.com/113d85ca959213ebe5176f4b8c7dbba50c5097d034c9acfcfac2a0d715931bdc-image.png)
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
bool UnionFindSetsJoin(int *pre, int x, int y, int *rst)
{
    int fx = UnionFindSetsFind(pre, x);
    int fy = UnionFindSetsFind(pre, y);
    if (fx == fy) return false;
    //printf("x:%d y:%d fx:%d fy:%d\n",x,y,fx,fy);
    if (fx != fy) {
        pre[fy] = fx;
        (*rst)--;
    }
    return true;
}
void UnionFindSetsInit(int *pre, int size)
{
    for (int i = 0; i < size; i++) {
        pre[i] = i;
    }
}
bool validTree(int n, int** edges, int edgesSize, int* edgesColSize){
    int *pre = (int *)calloc(n+1, sizeof(int));
    int rst = n;
    UnionFindSetsInit(pre, n+1);
    for (int i = 0; i < edgesSize; i++) {
        if (UnionFindSetsJoin(pre, edges[i][0], edges[i][1], &rst) == false){
            free(pre);
            return false;
        }
    }
    //for (int i = 0; i < n+1; i++) printf("%d ", pre[i]);
    free(pre);
    return rst == 1;
}
```
