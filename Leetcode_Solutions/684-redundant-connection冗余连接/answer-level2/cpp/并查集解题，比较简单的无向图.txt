### 解题思路

思路：
1、题目很明确的给定了只有一条多余的边，所以只要不断遍历，出现重复连通的情况，就是结果。
2、并查集可以解决，因为有连通性的边都指向了同一个父亲节点，当出现两个坐标父亲节点相同时，其实这条边就是多余的。

12ms 8.5M
--- wangtao HW-2020/4/1

### 代码

```cpp
class DSU {
public:
    vector<int> F;
    DSU(int N) {
        F.resize(N + 1, 0);
        for (int i = 0; i <= N; i++) {
            F[i] = i;
        }
    }

    int Find(int x) {
        if (x != F[x]) {
            F[x] = Find(F[x]);
        }
        return F[x];
    }

    bool Union(int x, int y) {
        int fx = Find(x);
        int fy = Find(y);
        if (fx != fy) {
            F[fx] = fy;
        } else {
            return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        DSU dsu(1001);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (dsu.Union(u, v)) {
                res.push_back(u);
                res.push_back(v);
                break;
            }
        }
        return res;
    }
};
```