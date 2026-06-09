### 解题思路
1.使用并查集判断多台电脑之间是否存在环路，记录多余的数目及多余的连接数目。
2.同时统计单独的和没有其他电脑有连接的电脑。
3.移动次数就是单独电脑的数目，因为需要把每台电脑都连上。

### 代码

```c
/*
并查集，初始是每个计算机在属于自己的集合，当加入有环路时就多一条线缆，最后用多余的线缆和多余的计算机比较。
*/
void InitParent(int n, int parent[n])
{
    for (int i = 0; i < n; ++i) {
        parent[i] = -1;
    }
}
int FindRoot(int x, int parentSize, int parent[parentSize])
{
    int root = x;
    while (root < parentSize && root >= 0 && parent[root] != -1 ){
        root = parent[root];
    }
    return root;
}
int makeConnected(int n, int** connections, int connectionsSize, int* connectionsColSize){
    int parent[n];
    InitParent(n, parent);
    int reduConnect = 0;
    int sigleComputer = n - 1;
    for (int i = 0; i < connectionsSize; ++i) {
        int rootA = FindRoot(connections[i][0], n, parent);
        int rootB = FindRoot(connections[i][1], n, parent);
        if (rootA == rootB) {
            reduConnect++;
        } else {
            //并集
            sigleComputer--;
            parent[rootA] = rootB;
        }
    }
    //printf("%d:%d\n", reduConnect, sigleComputer);
    return (reduConnect >= sigleComputer) ? sigleComputer : -1;
}

```