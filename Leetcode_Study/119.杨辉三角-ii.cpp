/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

/*

https://leetcode.cn/problems/pascals-triangle-ii/

119. 杨辉三角 II

简单
455
company
亚马逊
company
高盛集团 Goldman Sachs
company
微软 Microsoft
给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。

示例 1:

输入: rowIndex = 3
输出: [1,3,3,1]

示例 2:

输入: rowIndex = 0
输出: [1]

示例 3:

输入: rowIndex = 1
输出: [1,1]

提示:

0 <= rowIndex <= 33

进阶：

你可以优化你的算法到 O(rowIndex) 空间复杂度吗？

*/

// @lc code=start
class Solution {
public:
    // 2023.2.2, by Hsinan, similar to LC 118, but as the given input is index and starts from 0, we need to +1, 
    // and once it reaches the rowIndex, return the ans[rowIndex] instead
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans(rowIndex+1);
        for (int i = 0; i < rowIndex+1; ++i) {
            ans[i] = vector<int>(i + 1, 1);
            for (int j = 1; j < i; ++j) ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
        return ans[rowIndex];
    }
};


// @lc code=end

