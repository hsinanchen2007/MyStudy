思路：

BFS 遍历，依次将每一个海洋(值为 0 的点)作为起点开始遍历，直到找到最近的陆地(值为 1 的点)终止，记录下遍历的深度即为距离，所有海洋的点遍历完后，返回遍历深度最大的值，这个思路复杂度太高，会存在大量的重复计算。我们可以转为以每一个陆地作为起点遍历，每遇到一个海洋将其标记记录下来，直到所有海洋均被标记时，此时的遍历深度即为所求最大距离。

代码实现：

```c++
class Solution {
public:
    const int directions[5] = {0, 1, 0, -1, 0};
    int maxDistance(vector<vector<int>>& grid) {
        int ret = 0;
        int N = grid.size();
        
        queue<pair<int, int>> q;
        // 将陆地(值为 1)的点入队
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        
        // 全是海洋或全是陆地
        if (q.size() == 0 || q.size() == N * N)
            return -1;

        while (!q.empty()) {
            int s = q.size();
            int r = 0;
            while (s != 0) {
                pair<int, int> front = q.front();
                q.pop();
                // 4 个方向遍历
                for (int i = 0; i < 4; i++) {
                    int nx = front.first + directions[i];
                    int ny = front.second + directions[i + 1];
                    if (nx >= N || ny >= N || nx < 0 || ny < 0 || grid[nx][ny] == 1)
                        continue;
                    r++;
                    // 这里没有新开二位数组做记录，而是直接在原数组上做标记
                    grid[nx][ny] = 1;
                    q.push({nx, ny});
                }
                s--;
            }
            if (r > 0)
                ret++;
        }
        
        return ret;
    }
};
```


更多题解欢迎关注 [Do Leetcode For Fun](https://zhuanlan.zhihu.com/c_1145647496591298560) 专栏~