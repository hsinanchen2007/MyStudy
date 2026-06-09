### 解题思路
第一反应是并查集，结果发现还没两遍遍历高效

### 代码

```cpp
class mergeFind {
public:
    mergeFind(int n)
    {
        for (int i = 0; i < n; ++i) {
            parent.push_back(i);
            rank.push_back(1);
        }
    }

    int find(int son)
    {
        if (son != parent[son]) {
            parent[son] = find(parent[son]);
        }

        return parent[son];
    }

    void merge(int x, int y)
    {
        int fx = find(x);
        int fy = find(y);

        if (fx != fy) {
            if (rank[fx] >= rank[fy]) {
                parent[fy] = fx;
                rank[fx] += rank[fy];
                rank[fy] = 1;
            } else {
                parent[fx] = fy;
                rank[fy] += rank[fx];
                rank[fx] = 1;
            }
        }
    }

    int mergedNum(void)
    {
        int answer = 0;

        for (auto each : rank) {
            if (each != 1) {
                answer += each;
            }
        }

        return answer;
    }
private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    int countServers(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        mergeFind mf(m * n);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    for (int k = j + 1; k < n; ++k) {
                        if (grid[i][k] == 1) {
                            mf.merge(i * n + j, i * n + k);
                        }
                    }

                    for (int k = i + 1; k < m; ++k) {
                        if (grid[k][j] == 1) {
                            mf.merge(i * n + j, k * n + j);
                        }
                    }
                }
            }
        }

        return mf.mergedNum();
    }
};
```