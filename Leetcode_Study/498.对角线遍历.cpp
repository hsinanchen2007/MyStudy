/*
 * @lc app=leetcode.cn id=498 lang=cpp
 *
 * [498] 对角线遍历
 */

/*

https://leetcode.cn/problems/diagonal-traverse/

498. 对角线遍历

中等
428
company
Facebook
company
微软 Microsoft
company
亚马逊
给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。

示例 1：

输入：mat = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,4,7,5,3,6,8,9]

示例 2：

输入：mat = [[1,2],[3,4]]
输出：[1,2,3,4] 

提示：

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
-105 <= mat[i][j] <= 105

*/

// @lc code=start
class Solution100 {
public:
    // 2023.1.31, from https://github.com/lzl124631x/LeetCode/blob/master/leetcode/498.%20Diagonal%20Traverse/s1.cpp
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty()) return {};
        vector<int> ans;
        int M = mat.size(), N = mat[0].size(), end = M * N;
        bool topRight = true;
        for (int i = 0, j = 0, c = 0; c < end; ++c) {
            ans.push_back(mat[i][j]);
            if (topRight) {
                if (j == N - 1) ++i, topRight = !topRight;
                else if (i == 0) ++j, topRight = !topRight;
                else --i, ++j;
            } else {
                if (i == M - 1) ++j, topRight = !topRight;
                else if (j == 0) ++i, topRight = !topRight;
                else ++i, --j;
            }
        }
        return ans;
    }
};


class Solution99 {
public:
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/576579/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    vector<int> findDiagonalOrder(vector<vector<int>>& w) {
        vector<int> res;
        if (w.empty() || w[0].empty()) return res;
        int n = w.size(), m = w[0].size();
        for (int i = 0; i < n + m - 1; i ++ ) {
            if (i % 2 == 0) {
                for (int j = min(i, n - 1); j >= max(0, 1 - m + i); j -- )
                    res.push_back(w[j][i - j]);
            } else {
                for (int j = max(0, 1 - m + i); j <= min(i, n - 1); j ++ )
                    res.push_back(w[j][i - j]);
            }
        }
        return res;
    }
};


class Solution98 {
public:
    // 2023.1.31, from https://walkccc.me/LeetCode/problems/0498/
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<int> ans(m * n);
        int d = 1;  // Left-bottom -> right-top
        int row = 0;
        int col = 0;

        for (int i = 0; i < m * n; ++i) {
        ans[i] = matrix[row][col];
        row -= d;
        col += d;
        // Out of bound
        if (row == m)
            row = m - 1, col += 2, d = -d;
        if (col == n)
            col = n - 1, row += 2, d = -d;
        if (row < 0)
            row = 0, d = -d;
        if (col < 0)
            col = 0, d = -d;
        }

        return ans;
    }
};


class Solution {
public:
    // 2023.1.31, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/diagonal-traverse.cpp
    // Time:  O(m * n)
    // Space: O(1)
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }
        
        vector<int> result;
        int row = 0, col = 0, d = 0;
        vector<vector<int>> dirs = {{-1, 1}, {1, -1}};
        
        for (int i = 0; i < matrix.size() * matrix[0].size(); ++i) {
            result.emplace_back(matrix[row][col]);
            row += dirs[d][0];
            col += dirs[d][1];

            if (row >= static_cast<int>(matrix.size())) {
                row = matrix.size() - 1;
                col += 2;
                d = 1 - d;
            } else if (col >= static_cast<int>(matrix[0].size())) {
                col = matrix[0].size() - 1;
                row += 2;
                d = 1 - d;
            } else if (row < 0)  {
                row = 0;
                d = 1 - d;
            } else if (col < 0)  {
                col = 0;
                d = 1 - d;
            }
        }
        
        return result;
    }
};


// @lc code=end

