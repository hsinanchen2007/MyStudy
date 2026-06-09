```cpp
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> indegree(n, vector<int> (m, 0));
        queue<pair<int, int>> Q;
        static int dx[] = {-1, 1, 0, 0};
        static int dy[] = {0, 0, -1, 1};
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                for (int k = 0; k < 4; k ++) {
                    int new_x = i + dx[k];
                    int new_y = j + dy[k];
                    if (0 <= new_x && new_x < n && 0 <= new_y && new_y < m &&
                        matrix[new_x][new_y] > matrix[i][j]) {
                            indegree[new_x][new_y] ++;
                        }
                }

        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++) {
                if (indegree[i][j] == 0)
                    Q.push(make_pair(i, j));
            }
        int len = 0;
        while (!Q.empty()) {
            int size = Q.size();
            for (int i = 0; i < size; i ++) {
                auto cur = Q.front();
                Q.pop();
                int cur_x = cur.first, cur_y = cur.second;
                for (int k = 0; k < 4; k ++) {
                    int new_x = cur_x + dx[k];
                    int new_y = cur_y + dy[k];
                    if (0 <= new_x && new_x < n && 0 <= new_y && new_y < m &&
                        matrix[cur_x][cur_y] < matrix[new_x][new_y] 
                        && --indegree[new_x][new_y] == 0)
                        Q.push(make_pair(new_x, new_y));
                }
            }
            len ++;
        }
        return len;
    }
};

```