
```
class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        vector<vector<int>> help(m, vector<int>(n, INT_MAX));
        help[0][0] = A[0][0];
        queue<pair<int, int>> que;
        que.push({0, 0});
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while(!que.empty()){
            pair<int, int> front = que.front();
            que.pop();
            for(int i = 0; i < 4; i ++){
                int new_i = front.first + directions[i][0], new_j = front.second + directions[i][1];
                if(new_i >= 0 && new_i < m && new_j >= 0 && new_j < n){
                    if(help[new_i][new_j] == INT_MAX || min(help[front.first][front.second], A[new_i][new_j]) > help[new_i][new_j]){
                        que.push({new_i, new_j});
                        help[new_i][new_j] = min(help[front.first][front.second], A[new_i][new_j]);
                    }
                }
            }
        }
        return help[m - 1][n - 1];
    }
};
```
