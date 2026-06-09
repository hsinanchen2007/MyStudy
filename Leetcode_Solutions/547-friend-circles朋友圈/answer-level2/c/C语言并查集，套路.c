![image.png](https://pic.leetcode-cn.com/defb86e95174f368fef389fe01b34de19bce26fcf20928b801dd88776aefa825-image.png)
```
int UnionFindSetsFind(int *pre, int x) {
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
void UnionFindSetsJoin(int* pre, int x, int y, int* rst) {
    int fx = UnionFindSetsFind(pre, x);
    int fy = UnionFindSetsFind(pre, y);
    if (fx != fy) {
        pre[fy] = fx;
        (*rst)--;
    }
}
void UnionFindSetsInit(int *pre, int size) {
    for (int i = 0; i < size; i++) {
        pre[i] = i;
    }
}
int findCircleNum(int** M, int MSize, int* MColSize){
    int pre[201] = {0};
    int m = MSize;
    int n = MColSize[0];

    UnionFindSetsInit(pre, sizeof(pre) / sizeof(int));
    int rst = MSize;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (M[i][j] == 1) {
                //join(pre, i, j);
                UnionFindSetsJoin(pre, i, j, &rst);
            }
        }
    }
    return rst;
}
```
