
```
class UnionFind {
private:
    vector<int> parents;
    vector<int> ranks;
public:
    int find(int);
    void doUnion(int, int);
    int count();
    UnionFind(int num);
};

int UnionFind::find(int a) {
    if (parents[a] != a) {
        parents[a] = find(parents[a]); //递归找出根节点
    }

    return parents[a];
}

void UnionFind::doUnion(int a, int b) {
    int aParent = find(a);
    int bParent = find(b);

    if (aParent != bParent) { //只有根节点不同，才有连通的必要
        if (ranks[a] < ranks[b]) {//把层次比较低的根节点挂到高的根节点上面，控制最终树的高度
            parents[aParent] = bParent;
        } else if (ranks[a] > ranks[b]) {
            parents[bParent] = aParent;
        } else {//如果两个树的高度相同，那就随便选一个挂到对方下面，根节点的高度+1
            parents[aParent] = bParent;
            ranks[bParent]++;
        }

    }
}

UnionFind::UnionFind(int num) : parents(num), ranks(num) {
    for (int i = 0; i < num; i++) {
        parents[i] = i; //初始化自己的根节点就是自己
        ranks[i] = 1; //用于路径压缩，初始化所有点的层级是1，子节点高度增加，层级增加
    }
}

int UnionFind::count() {
    int ans = 0;
    for (int i = 0; i < parents.size(); i++) {
        if (find(i) == i) ans++; //找出所有根节点的个数，就是连通分量的个数
    }

    return ans;
}

class Solution {
public:
    int countComponents(int n, vector<vector<int> >& edges) {
        UnionFind uf = UnionFind(n);
        for (auto edge: edges) {
            uf.doUnion(edge[0], edge[1]); // 将每个边对应的两个节点连通
        }

        return uf.count();
    }
};
```
