/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

/*

https://leetcode.cn/problems/rotting-oranges/

994. 腐烂的橘子
中等
650
company
亚马逊
company
优步 Uber
company
彭博 Bloomberg

在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：

值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。

返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。

示例 1：

输入：grid = [[2,1,1],[1,1,0],[0,1,1]]
输出：4

示例 2：

输入：grid = [[2,1,1],[0,1,1],[1,0,1]]
输出：-1
解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4 个正向上。

示例 3：

输入：grid = [[0,2]]
输出：0
解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] 仅为 0、1 或 2

*/

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // build initial set of rotten oranges
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        // mark the start of a minute
        q.push({-1, -1});
        
        int result = -1;
        
        // start rotting process via BFS
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            if (row == -1) {
                // finish 1 minute of processing, mark next minute
                result++;
                if (!q.empty()) {
                    q.push({-1, -1});
                }
            } else {
                // rotten orange, contaminate its neighbors
                for (int i = 0; i < dirs.size(); i++) {
                    int x = row + dirs[i][0];
                    int y = col + dirs[i][1];
                    
                    if (x < 0 || x >= m || y < 0 || y >= n) {
                        continue;
                    }
                    
                    if (grid[x][y] == 1) {
                        // contaminate
                        grid[x][y] = 2;
                        fresh--;
                        // this orange will now contaminate others
                        q.push({x, y});
                    }
                }
            }
        }
        
        if (fresh == 0) {
            return result;
        }
        return -1;
    }
private:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};


// @lc code=end

