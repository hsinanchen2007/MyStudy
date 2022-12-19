### 解题思路
从陆地着手开始扩散，原地记录海洋到陆地的距离。为了区分是否已经遍历过，我们把距离用负数标记，把陆地用1标记，已经标记过的陆地用2标记。
一开始还觉得想法挺巧妙的，后来意识到其实只要记录BFS的轮次即可，不过写都写了。

[自己动手实现分布式缓存](https://github.com/wfnuser/burrow)
[我的题解](https://www.github.com/wfnuser/leetcode)
[我的github](https://www.github.com/wfnuser)
欢迎大家在github follow我 对分布式缓存感兴趣的可以看第一个项目，希望之后可以发布更多的玩具项目

### 代码

```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, int>> lands;
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    lands.push(make_pair(i, j));
                }
            }
        }

        if (lands.size() == 0 || lands.size() == m*n) return -1;

        int dx[4] = {1,-1,0,0};
        int dy[4] = {0,0,1,-1};

        while(!lands.empty()) {
            int size = lands.size();
            for (int c = 0; c < size; c++) {
                pair<int, int> land = lands.front();
                lands.pop();
                int i = land.first;
                int j = land.second;

                if (grid[i][j] == 2) continue;

                for (int d = 0; d < 4; d++) {
                    int ii = i + dx[d];
                    int jj = j + dy[d];
                    if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
                    if (grid[ii][jj] == 2 || grid[ii][jj] < 0) continue;

                    if (grid[ii][jj] == 1) {
                        grid[i][j] = 2;
                        lands.push(make_pair(ii, jj));
                        continue;
                    }

                    if (grid[ii][jj] == 0) {
                        if (grid[i][j] >= 1) {
                            grid[ii][jj] = -1;
                        } else {
                            grid[ii][jj] = grid[i][j] - 1;
                        }
                        lands.push(make_pair(ii, jj));
                    }

                    ans = max(ans, -grid[ii][jj]);
                }

                grid[i][j] = 2;
            }
        }
        
        return ans;
    }
};
```