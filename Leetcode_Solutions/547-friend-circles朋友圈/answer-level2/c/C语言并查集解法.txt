### 解题思路
此处撰写解题思路

### 代码

```c
#define MAX_NUM 300
int uf_count = 0; // 连通分量
int parent[MAX_NUM] = { 0 }; // x的父节点是parent[x]
int size[MAX_NUM] = { 0 }; // 记录每个节点下子节点的数量

void UFInit(int n)
{
    int i;
    for (i = 0; i < n; i++) {
         parent[i] = i;
         size[i] = 1;
    }
    uf_count = n;
}

/* 返回某个节点x的根节点 */
int Find(int x)
{
    /* 节点x的父节点是自身，则该节点为根节点 */
    while(parent[x] != x) {
        parent[x] = parent[parent[x]]; // 遍历的同时压缩路径
        x = parent[x];
    }
    return x;
}

/* 将节点x与y连通 */
void Union(int x, int y)
{
    int rootp = Find(x); // x的根节点
    int rootq = Find(y); // y的根节点
    if (rootp == rootq) { // 已是连通的
        return;
    }
    /* 根据size优化，将小树接到大树下面，使得树尽量平衡 */
    if (size[rootp] > rootq) {
        parent[rootq] = rootp; // 将p的父节点设为q
        size[rootp] += size[rootq];
    } else {
        parent[rootp] = rootq;
        size[rootq] += size[rootp];
    }
    uf_count--; // 连通分量减1
}

int findCircleNum(int** M, int MSize, int* MColSize){
    int i;
    int j;
    UFInit(MSize);
    for (i = 0; i < MSize; i++) {
        for (j = 0; j < i; j++) {
            if (M[i][j] == 1) {
                Union(i, j);
            }
        }
    }
    return uf_count;
}
```