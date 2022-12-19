**标准并查集题目,直接上代码**
```
class Solution {
public:
    vector<int> father; // father[i] 表示以i为下标的父亲节点
    vector<int> child; // 每个节点的孩子数量
    int num; // 全连通需要的最少线缆数

    void initUnionFind(int n) {
        this->father = vector<int>(n);
        this->child = vector<int>(n, 1);
        this->num = n - 1;
        for (int i = 0; i < n; ++i) {
            father[i] = i;
        }
    }

    int find(int n) {
        if (n != father[n]) {
            father[n] = find(father[n]);
        }
        return father[n];
    }

    // 压缩查找路径
    void unionFather(int a, int b) {
        int i = find(a);
        int j = find(b);
        if (i == j) {
            return;
        }
        if (child[i] < child[j]) {
            father[i] = father[j];
            child[j] += child[i];
        } else {
            father[j] = father[i];
            child[i] += child[j];
        }
    }

    int makeConnected(int n, vector<vector<int>> &connections) {
        // 不满足最低线缆数
        if (connections.size() < n - 1) {
            return -1;
        }
        initUnionFind(n);
        for (auto &v  : connections) {
            int a = v[0];
            int b = v[1];
            if (find(a) != find(b)) {
                // 关键节点必须用线缆,所以线缆数总数-1
                num--;
            }
            unionFather(a, b);
        }
        return this->num;
    }
};
```
