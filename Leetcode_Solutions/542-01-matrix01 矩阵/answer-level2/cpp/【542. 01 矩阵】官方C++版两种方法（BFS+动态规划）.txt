## 思路一：BFS
### 代码
时间复杂度：O(r * c)，因为每个节点只会加入队列一次，不会多次加入。
空间复杂度：O(r * c)
```c++
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {                
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
        queue<pair<int, int>> que;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                    que.push({i, j});
                }                
            }
        }        
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!que.empty()) {
            pair<int, int> cur = que.front(); 
            que.pop();
            for (auto d : dir) {
                int x = cur.first + d[0];
                int y = cur.second + d[1];
                if (x >= 0 && x < r && y >= 0 && y < c) {
                    if (dist[x][y] > dist[cur.first][cur.second] + 1) {
                        dist[x][y] = dist[cur.first][cur.second] + 1;
                        que.push({x, y});
                    }
                }
            }
        }
        return dist;
    }
};
```

## 思路二：动态规划
### 代码
时间复杂度：O(r * c)，两遍扫描
空间复杂度：O(r * c)
```c++
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {                
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<int>> dist(r, vector<int>(c, INT_MAX - 10000));        
        //1. 从上到下，从左到右遍历矩阵
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;                    
                } else {
                    if (i > 0) dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                    if (j > 0) dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }                
            }
        }        
        //2. 从下到上，从右到左遍历
        for (int i = r - 1; i >= 0; --i) {
            for (int j = c - 1; j >= 0; --j) {
                if (i < r - 1) dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                if (j < c - 1) dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
            }
        }
        return dist;
    }
};
```
