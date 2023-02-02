/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

/*

https://leetcode.cn/problems/pascals-triangle/

118. 杨辉三角

简单
904
company
亚马逊
company
彭博 Bloomberg
company
谷歌 Google
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。

示例 1:

输入: numRows = 5
输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

示例 2:

输入: numRows = 1
输出: [[1]] 

提示:

1 <= numRows <= 30

*/

// @lc code=start
class Solution100 {
public:
    // 2023.2.2, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/118.%20Pascal's%20Triangle
    // OJ: https://leetcode.com/problems/pascals-triangle/
    // Author: github.com/lzl124631x
    // Time: O(N^2)
    // Space: O(1)
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; ++i) {
            ans[i] = vector<int>(i + 1, 1);
            for (int j = 1; j < i; ++j) ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
        return ans;
    }
};


class Solution {
public:
    // 2023.2.2, from https://walkccc.me/LeetCode/problems/0118/
    // Time: O(n^2)
    // Space: O(n^2)
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; ++i)
            ans.push_back(vector<int>(i + 1, 1));

        for (int i = 2; i < numRows; ++i)
            for (int j = 1; j < ans[i].size() - 1; ++j)
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];

        return ans;
    }
};


// @lc code=end

