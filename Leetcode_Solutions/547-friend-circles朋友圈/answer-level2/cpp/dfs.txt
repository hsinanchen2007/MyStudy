### 解题思路
进入dfs的次数即为朋友圈的个数

### 代码

```cpp
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> visited(M.size(), 0);
        
        int result = 0;
        for (int i = 0; i < M.size(); ++i) {
            if (visited[i] == 0) {
                dfs(M, visited, i);
                result += 1;
            }
        }
        
        return result;
    }
private:
    void dfs(const vector<vector<int>>& matrix, vector<int>& visited, int cur) {
        visited[cur] = 1;
        
        for (int i = cur + 1; i < matrix.size(); ++i) {
            if (matrix[cur][i] == 1 && visited[i] == 0) {
                dfs(matrix, visited, i);
            }
        }
        
        for (int i = 0; i < cur; ++i) {
            if (matrix[i][cur] == 1 && visited[i] == 0) {
                dfs(matrix, visited, i);
            }
        }
    }
};
```