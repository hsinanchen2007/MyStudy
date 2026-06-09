
C++解答，一次搞定！内存12M击败100%，执行时间152ms击败17%==！
**思路：**
遍历每一个海洋，对每个海洋按圈循环扩大查找，关键点在于处理好每次扩大的“半径”，以及对这个**正方形**遍历查找是否存在陆地，存在则返回最小距离，最后对每个海洋的最小距离取最大值。
**代码：**
```
class Solution {
   public:
    int findMaxDistance(vector<vector<int>>& grid, int i, int j) {
        int distance = 10000;
        int recursiveTimes = max(max(i, (int)(grid.size() - i - 1)), max(j, (int)(grid[0].size() - j - 1)));
        for (int len = 1; len <= recursiveTimes; ++len) {
            // 遍历边长为len*2的正方形  
            // 遍历上边和下边
            int x1 = i - len;
            int x2 = i + len;
            for (int y = max(0, j - len); y <= min(j + len,(int)(grid[0].size() - 1) );
                 ++y) {
                if (x1 >= 0) {
                    if (grid[x1][y] == 1) {
                        distance = distance < len + abs(y - j) ? distance : len + abs(y - j);
                    }
                }
                if (x2 < grid.size()) {
                    if (grid[x2][y] == 1) {
                        distance = distance < len + abs(y - j) ? distance : len + abs(y - j);
                    }
                }
            }
            // 遍历左边和右边
            int y1 = j - len;
            int y2 = j + len;
            for (int x = max(0, i - len + 1);
                 x <= min((int)(grid.size() - 1), i + len - 1); ++x) {
                if (y1 >= 0) {
                    if (grid[x][y1] == 1) {
                        distance = distance < len + abs(x - i) ? distance : len + abs(x - i);
                    }
                }
                if (y2 < grid[0].size()) {
                    if (grid[x][y2] == 1) {
                        distance = distance < len + abs(x - i) ? distance : len + abs(x - i);
                    }
                }
            }
            if (distance != 10000) {
                return distance;
            }
        }
        return -1;
    }

    int maxDistance(vector<vector<int>>& grid) {
        int maxDistance = -1;
        // 对每个岛屿做遍历
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] != 0) {
                    continue;
                }
                int distance = findMaxDistance(grid, i, j);
                maxDistance = maxDistance > distance ? maxDistance : distance;
            }
        }
        return maxDistance;
    }
};
```
