```
class Solution {
public:
    // rank为秩
    int *father, *rank;
    void init(int size) {
        father = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; ++i) { father[i] = i, rank[i] = 0; }
    }
    // 更新father[node]，压缩路径
    int find(int node) {
        if (father[node] != node) {
            father[node] = find(father[node]);
        }
        return father[node];
    }
    // 按秩合并
    bool merge(int node1, int node2) {
        int ancestor1 = find(node1);
        int ancestor2 = find(node2);
        if (ancestor1 != ancestor2) {
            if (rank[ancestor1] > rank[ancestor2]) { swap(ancestor1, ancestor2); }
            father[ancestor1] = ancestor2;
            rank[ancestor2] = max(rank[ancestor2], rank[ancestor1] + 1);
            return true;
        }
        return false;
    }
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        init(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (M[i][j]) {
                    merge(i, j);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (find(i) == i) { ++ans; }
        }
        return ans;
    }
};
```
