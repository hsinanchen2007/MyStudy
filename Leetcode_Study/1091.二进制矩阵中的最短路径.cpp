/*
 * @lc app=leetcode.cn id=1091 lang=cpp
 *
 * [1091] 二进制矩阵中的最短路径
 */

/*

https://leetcode.cn/problems/shortest-path-in-binary-matrix/

1091. 二进制矩阵中的最短路径

中等
244
company
Facebook
company
亚马逊
company
谷歌 Google

给你一个 n x n 的二进制矩阵 grid 中，返回矩阵中最短 畅通路径 的长度。如果不存在这样的路径，返回 -1 。

二进制矩阵中的 畅通路径 是一条从 左上角 单元格（即，(0, 0)）到 右下角 单元格（即，(n - 1, n - 1)）的路径，该路径同时满足下述要求：

路径途经的所有单元格都的值都是 0 。
路径中所有相邻的单元格应当在 8 个方向之一 上连通（即，相邻两单元之间彼此不同且共享一条边或者一个角）。
畅通路径的长度 是该路径途经的单元格总数。

 
示例 1：

输入：grid = [[0,1],[1,0]]
输出：2

示例 2：

输入：grid = [[0,0,0],[1,1,0],[1,1,0]]
输出：4

示例 3：

输入：grid = [[1,0,0],[1,1,0],[1,1,0]]
输出：-1 

提示：

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] 为 0 或 1

*/

// @lc code=start
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        static const vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1},
                                                          { 0, -1}, { 0, 1},
                                                          { 1, -1}, { 1, 0}, { 1, 1}};
        int result = 0;
        queue<pair<int, int>> q({{0, 0}});
        while (!q.empty()) {
            ++result;
            queue<pair<int, int>> next_depth;
            while (!q.empty()) {
                int i, j;
                tie(i, j) = q.front(); q.pop();
                if (0 <= i && i < grid.size() &&
                    0 <= j && j < grid[0].size() &&
                    !grid[i][j]) {
                    grid[i][j] = 1;
                    if (i == grid.size() - 1 && j == grid.size() - 1) {
                        return result;
                    }
                    for (const auto& dir : directions) {
                        next_depth.emplace(i + dir.first, j + dir.second);
                    }
                }
            }
            q = move(next_depth);
        }
        return -1;
    }
};


// @lc code=end

