### 解题思路
由题可知，每一行代表一个人
1. 先访问该人的所有朋友
2. 递归访问朋友的朋友
3. 为避免重复递归访问，使用visited记录已访问过的朋友

### 代码
```cpp
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) {
            return 0;
        }
        
        int cnt = 0;
        int rows = M.size() - 1;
        vector<bool> visited(M.size(), false);
        for (int r = 0; r <= rows; ++r) {
            if (visited[r]) {
                continue;
            }
            dfs(M, r, visited);
            ++cnt;
        }
        return cnt;
    }
    
    void dfs(vector<vector<int>>& M, int row, vector<bool>& visited) {
        if (row >= M.size() || visited[row]) {
            return;
        }
        
        visited[row] = true;
        for (int j = 0; j < M.size(); ++j) {
            if (M[row][j] == 0) {
                continue;
            }
            M[row][j] = -1;
            M[j][row] = -1;
            if (j == row) {
                continue;
            }
            dfs(M, j, visited);
        }
    }
};
```