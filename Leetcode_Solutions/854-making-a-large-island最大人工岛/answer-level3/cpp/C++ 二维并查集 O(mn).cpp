```cpp
class Solution {
public:
    class UnionFind2D {
    public:
        int count;
        int countK = 0;
        vector<int> nodes;

        UnionFind2D(int x, int y, vector<vector<int>> data) {
            nodes = vector<int>(data.size() * data[0].size(), -1);
            for (int i = 0; i < x; ++i)
                for (int j = 0; j < y; ++j)
                    if (data[i][j])
                        nodes[i * data[0].size() + j] = i * data[0].size() + j;
                    else
                        countK++;
            count = nodes.size();
        }

        int find(int x) {
            if (nodes[x] != x)
                nodes[x] = find(nodes[x]);
            return nodes[x];
        }

        void unionELe(int a, int b) {
            int pa = find(a);
            int pb = find(b);
            if (pa != pb) {
                count--;
                nodes[pb] = pa;
            }
        }
    };
    
    int largestIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        UnionFind2D uf2d(m, n, grid);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    if (j != 0 && grid[i][j - 1])
                        uf2d.unionELe(i*n + j, i*n + j - 1);
                    if (j != n - 1 && grid[i][j + 1])
                        uf2d.unionELe(i*n + j, i*n + j + 1);
                    if (i != 0 && grid[i - 1][j])
                        uf2d.unionELe(i*n + j, i*n + j - n);
                    if (i != m - 1 && grid[i + 1][j])
                        uf2d.unionELe(i*n + j, i*n + j + n);
                }
            }
        }
        unordered_map<int, int> islandArea;
        for (int i = 0; i < uf2d.nodes.size(); ++i)
            if (uf2d.nodes[i] != -1)
                ++islandArea[uf2d.find(i)];
        int result = 0;
        for (auto it = islandArea.begin(); it != islandArea.end(); ++it)
            result = max(result, it->second);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!grid[i][j]) {
                    int tmp = 1;
                    unordered_set<int> tmpSet;
                    if (i != 0 && grid[i - 1][j])
                        tmpSet.insert(uf2d.find(i * n + j - n));
                    if (i != m - 1 && grid[i + 1][j])
                        tmpSet.insert(uf2d.find(i * n + j + n));
                    if (j != 0 && grid[i][j - 1])
                        tmpSet.insert(uf2d.find(i * n + j - 1));
                    if (j != n - 1 && grid[i][j + 1])
                        tmpSet.insert(uf2d.find(i * n + j + 1));
                    for (int i : tmpSet)
                        tmp += islandArea[i];
                    result = max(result, tmp);
                }
            }
        }
        return result;
    }
};
```
