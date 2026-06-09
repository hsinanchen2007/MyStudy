### 解题思路
经典并查集，带路径压缩

### 代码

```cpp
class MergeFind {
public:
    MergeFind(int n)
    {
        for (int i = 0; i < n; ++i) {
            parent.push_back(i);
            rank.push_back(1);
        }
        circles = n;
    }

    int Find(int son)
    {
        if (son != parent[son]) {
            parent[son] = Find(parent[son]);
        }

        return parent[son];
    }

    void Merge(int x, int y)
    {
        int rootX = Find(x);
        int rootY = Find(y);

        if (rootX == rootY) {
            return;
        }

        if (rank[rootX] >= rank[rootY]) {
            parent[rootY] = rootX;
            rank[rootX] += rank[rootY];
        } else {
            parent[rootX] = rootY;
            rank[rootY] += rank[rootX];
        }

        circles -= 1;
    }

    int Connected(void)
    {
        return circles;
    }
private:
    vector<int> parent;
    vector<int> rank;
    int circles;
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        MergeFind mf(n);

        for (auto each : edges) {
            mf.Merge(each.front(), each.back());
        }

        return mf.Connected();
    }
};
```