#### 思路
- 遍历所有的边`edges`，将连通的结点放入同一个集合，形成一个联通分量$G$。
- 在遍历的过程中，如果边$(a, b)$的两个结点$a$, $b$已经属于同一联通分量，则$(a, b)$就是该联通分量的冗余边。

#### 使用并查集实现
```cpp
class Solution {
private:
    int parent[1001];
    int find_root(int x) {
        while (parent[x] != x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    bool union_root(int x, int y) {
        int root_x = find_root(x);
        int root_y = find_root(y);
        if (root_x == root_y) {
            return false;
        }
        parent[root_x] = root_y;
        return true;
    }    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (int i = 1; i <= 1000; i++) {
            parent[i] = i;
        }        
        for (auto edge : edges) {
            if (!union_root(edge[0], edge[1])) {
                return edge;
            }
        }
        return {};
    }
};
```