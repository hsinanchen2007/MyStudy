### 解题思路
BFS遍历所有位置，如果已经遍历过，直接跳过。

### 代码

```cpp

# define PR pair<int, int>

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0){
            return 0;
        }
        int n = grid[0].size();
        if(n == 0){
            return 0;
        }
        int res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<int> delta = {0, 1, 0, -1, 0};
        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visited[i][j] == false && grid[i][j] == 1){
                    int tmp = 1;
                    visited[i][j] = true;
                    queue<PR> q;
                    q.push({i, j});
                    while(!q.empty()){
                        PR pos = q.front();
                        q.pop();
                        int x = pos.first;
                        int y = pos.second;
                        for(int k = 0; k < 4; k++){
                            int dx = x + delta[k];
                            int dy = y + delta[k+1];
                            if(dx >= 0 && dx < m && dy >= 0 && dy < n && visited[dx][dy] == false && grid[dx][dy] == 1){
                                tmp++;
                                visited[dx][dy] = true;
                                q.push({dx, dy});
                            }
                        }
                    }
                    res = max(res, tmp);
                }
            }
        }
        return res;
    }
};
```