### 解题思路
参考了https://leetcode-cn.com/problems/rotting-oranges/solution/yan-du-you-xian-sou-suo-python3-c-by-z1m/
首先将腐烂水果的坐标记录下来，并加入到第一轮腐烂队列queue<pair<int,int>> rotten，同时记录新鲜水果的数目count，行列的边界Row_MAX，Column_MAX。
时间用腐烂的传递轮数来记录，第一轮模拟将队列中腐烂水果的腐烂传染至四个方向的新鲜水果，把队列中的本轮腐烂水果弹出，并将新腐烂的水果重新加入到队列，开始第二轮的腐烂传染。。。
等到队列为空时，如果新鲜水果的个数大于0，则返回-1；个数为0，则返回腐烂的轮数。

### 代码

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
    int Row_MAX = grid.size();
    int Column_MAX = grid[0].size();
    queue<pair<int,int>> rotten;
    pair<int,int> orange(0,0);
    int count = 0;          // count 表示新鲜橘子的数量
    for (int r = 0; r < Row_MAX; r++) {
        for (int c = 0; c < Column_MAX; c++) {
            if (grid[r][c] == 1) 
            {
                count++;
            } 
            else if (grid[r][c] == 2) 
            {
                rotten.push({r, c});
            }
        }
    }

    int round = 0;          // round 表示腐烂的轮数，或者分钟数
    while (count > 0 && !rotten.empty()) {
        round++;
        int n = rotten.size();
        for (int i = 0; i < n; i++) {
            orange = rotten.front();
            rotten.pop();
            int r = orange.first;
            int c = orange.second;
            if (r-1 >= 0 && grid[r-1][c] == 1) {
                grid[r-1][c] = 2;
                count--;
                rotten.push({r-1, c});
            }
            if (r+1 < Row_MAX && grid[r+1][c] == 1) {
                grid[r+1][c] = 2;
                count--;
                rotten.push({r+1, c});
            }
            if (c-1 >= 0 && grid[r][c-1] == 1) {
                grid[r][c-1] = 2;
                count--;
                rotten.push({r, c-1});
            }
            if (c+1 < Column_MAX && grid[r][c+1] == 1) {
                grid[r][c+1] = 2;
                count--;
                rotten.push({r, c+1});
            }
        }
    }

    if (count > 0) {
        return -1;
    } else {
        return round;
    }
    }
};
```