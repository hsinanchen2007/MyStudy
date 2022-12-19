### 解题思路
此处撰写解题思路
注意一点，找爹记得路径压缩，也就是father[t] = getFather(father, father[t]);
Merge后更新的是找到的2个father节点其中某一个节点的爹。
### 代码

```c
int getFather(int *fahter, int t)
{
    if (fahter[t] == t) {
        return fahter[t];
    }
    fahter[t] = getFather(fahter, fahter[t]);
    return fahter[t];
}

void merge(int *father, int t1, int t2)
{
    int f1 = getFather(father, t1);
    int f2 = getFather(father, t2);
    /* 合并更新的是爹的爹 */
    if (f1 > f2) {
        father[f1] = f2;
    } else {
        father[f2] = f1;
    }
}

struct NetInfo {
    int itemsNum;
    int connectionNum;
};

int makeConnected(int n, int** connections, int connectionsSize, int* connectionsColSize){
    if (n == 0 || connections == NULL || connectionsSize == 0 || connectionsColSize == NULL) {
        return -1;
    }
    int *father = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        father[i] = i;
    }
    /* 数据处理 */
    for (int i = 0; i < connectionsSize; i++) {
        merge(father, connections[i][0], connections[i][1]);        
    }
    for (int i = 0; i < n; i++) {
        father[i] = getFather(father, i);
    }
    /* 计算 */
    struct NetInfo *nets = (struct NetInfo *)malloc(n * sizeof(struct NetInfo));
    memset(nets, 0, n * sizeof(struct NetInfo));   
    for (int i = 0; i < n; i++) {
        int netId = father[i];
        nets[netId].itemsNum++;
    }

    int netCnt = 0;
    for (int i = 0; i < n; i++) {
        if (nets[i].itemsNum != 0) {
            netCnt++;
        }
    }
    if (netCnt == 1) {
        return 0;
    }
    for (int i = 0; i < connectionsSize; i++) {
        nets[father[connections[i][0]]].connectionNum += 1;
    }
    int remainLines = 0;
    for (int i = 0; i < n; i++) {
        if (nets[i].itemsNum != 0) {
            remainLines += (nets[i].connectionNum - (nets[i].itemsNum - 1));
        }
    }
    if (remainLines >= netCnt - 1) {
        return netCnt - 1;
    } else {
        return -1;
    }
}

```