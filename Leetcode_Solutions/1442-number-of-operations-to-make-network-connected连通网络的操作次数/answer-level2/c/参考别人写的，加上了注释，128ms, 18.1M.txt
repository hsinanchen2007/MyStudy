
```

int *root;
/* 得到x的根节点，也就是满足root[idx] == -1的idx */
int Root(int x)
{
    if (root[x] == -1) { // 自身为根，则直接返回
        return x;
    }
    int idx = x;     
    while (root[idx] != -1) { // 更新其节点值
        idx = root[idx];
    }
    root[x] = idx;
    return idx;
}

/* 得到a和b的根节点，并使得两者根节点相同 */ 
void FindRoot(int a, int b)
{
    int aRoot = Root(a);
    int bRoot = Root(b);
    if (bRoot != aRoot) {
        root[bRoot] = aRoot;
    }
}
int makeConnected(int n, int** connections, int connectionsSize, int* connectionsColSize){
    /* 线少于n-1无法连通 */
    if (connectionsSize < n - 1) {
        return -1;
    }
    root = (int *)malloc(n * sizeof(int));
    memset(root, 0xff, n * sizeof(int));

    /* 能连通， 找连通域个数 */
    for (int i = 0; i < connectionsSize; i++) {
        FindRoot(connections[i][0], connections[i][1]); // 同一根线连通的电脑根节点相同
    }

    /* root[i] == -1的点即为根节点 */
    int block = 0;
    for (int i = 0; i < n; i++) {
        block += (root[i] == -1); // 根节点的个数即为连通域个数
    }
    return block - 1;
}


```
