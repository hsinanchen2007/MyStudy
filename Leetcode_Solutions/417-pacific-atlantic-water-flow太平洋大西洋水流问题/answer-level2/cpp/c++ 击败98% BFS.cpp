不优化空间复杂度，只求写起来简单，执行效率高
![Screen Shot 2020-02-10 at 4.43.59 PM.png](https://pic.leetcode-cn.com/adde95663150cbc749ffc79a323ca8ffe60996619ff683794c1d166c20a7e02e-Screen%20Shot%202020-02-10%20at%204.43.59%20PM.png)

声明pacific和atlantic两个二维数组，记录可流到两大洋的位置。得到位置的方法直接用BFS从一定可以流到的位置开始扩散，直到找不到新的位置时，即得到了所有可能的位置。
遍历一遍所有位置，如果pacific和atlantic两个数组皆有标记，则记录该位置到答案。

[自己动手实现分布式缓存](https://github.com/wfnuser/burrow)
[我的题解](https://www.github.com/wfnuser/leetcode)
[我的github](https://www.github.com/wfnuser)
欢迎大家在github follow我 对分布式缓存感兴趣的可以看第一个项目，希望之后可以发布更多的玩具项目

```
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int m = matrix.size();
        if (m == 0) return ans;
        int n = matrix[0].size();
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        
        // find pacific
        queue<pair<int, int>> Q;
        for(int i = 0; i < m; i++) {
            pacific[i][0] = 1;
            Q.push(make_pair(i, 0));
        }
        for(int j = 1; j < n; j++) {
            pacific[0][j] = 1;
            Q.push(make_pair(0, j));
        }
        while(!Q.empty()) {
            pair<int, int> pos = Q.front();
            Q.pop();

            for (int d = 0; d < 4; d++) {
                int ii = pos.first + dx[d];
                int jj = pos.second + dy[d];
                if (ii < 0 || jj < 0 || ii >= m || jj >= n) continue;
                if (pacific[ii][jj]) continue;
                if (matrix[ii][jj] >= matrix[pos.first][pos.second]) {
                    pacific[ii][jj] = 1;
                    Q.push(make_pair(ii, jj));
                }
            }
        }

        for(int i = 0; i < m; i++) {
            atlantic[i][n-1] = 1;
            Q.push(make_pair(i, n-1));
        }
        for(int j = 0; j < n-1; j++) {
            atlantic[m-1][j] = 1;
            Q.push(make_pair(m-1, j));
        }
        while(!Q.empty()) {
            pair<int, int> pos = Q.front();
            Q.pop();

            for (int d = 0; d < 4; d++) {
                int ii = pos.first + dx[d];
                int jj = pos.second + dy[d];
                if (ii < 0 || jj < 0 || ii >= m || jj >= n) continue;
                if (atlantic[ii][jj]) continue;
                if (matrix[ii][jj] >= matrix[pos.first][pos.second]) {
                    atlantic[ii][jj] = 1;
                    Q.push(make_pair(ii, jj));
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (atlantic[i][j] && pacific[i][j]) ans.push_back(vector<int>{i, j});
            }
        }

        return ans;
    }
};
```
