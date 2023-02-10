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


class Solution99 {
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


class Solution98 {
public:
    // 2023.2.10, from https://github.com/grandyang/leetcode/issues/118
    /*
        杨辉三角是二项式系数的一种写法，如果熟悉杨辉三角的五个性质，那么很好生成，可参见我的上一篇博文Pascal's Triangle II。
        具体生成算是：每一行的首个和结尾一个数字都是1，从第三行开始，中间的每个数字都是上一行的左右两个数字之和。代码如下：    
    */
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows, vector<int>());
        for (int i = 0; i < numRows; ++i) {
            res[i].resize(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        return res;
    }
};


class Solution97 {
public:
    // 2023.2.10, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/pascals-triangle.cpp
    // Time:  O(n^2)
    // Space: O(1)
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; ++i) {
            result.push_back({});
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) {
                    result[i].emplace_back(1);
                } else {
                    result[i].emplace_back(result[i - 1][j - 1] +
                                           result[i - 1][j]);
                }
            }
        }
        return result;
    }
};


class Solution96 {
public:
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


class Solution95 {
public:
    // 2023.2.10, from https://walkccc.me/LeetCode/problems/0118/
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


class Solution {
public:
    // 2023.2.10, from https://zxi.mytechroad.com/blog/?s=LeetCode+118.
    // Author: Huahua
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows;++i) {
        ans[i].resize(i + 1);
        ans[i][0] = ans[i][i] = 1;
        for (int j = 1; j < i; ++j)
            ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
        }
        return ans;
    }
}


// @lc code=end
