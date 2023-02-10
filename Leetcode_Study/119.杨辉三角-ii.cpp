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
class Solution100 {
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


class Solution99 {
public:
    // 2023.2.10, from https://github.com/grandyang/leetcode/issues/119
    /*
        杨辉三角想必大家并不陌生，应该最早出现在初高中的数学中，其实就是二项式系数的一种写法。

        　　　　　　　　１
        　　　　　　　１　１
        　　　　　　１　２　１
        　　　　　１　３　３　１
        　　　　１　４　６　４　１
        　　　１　５　10　10　５　１
        　　１　６　15　20　15　６　１
        　１　７　21　35　35　21　７　１
        １　８　28　56　70　56　28　８　１
        杨辉三角形第n层（顶层称第0层，第1行，第n层即第 n+1 行，此处n为包含0在内的自然数）正好对应于二项式 \left(a+b\right)^{n} 展开的系数。
        例如第二层 1 2 1 是幂指数为2的二项式 \left(a+b\right)^{2} 展开形式 a^{2}+2ab+b^{2} 的系数。

        杨辉三角主要有下列五条性质：

        杨辉三角以正整数构成，数字左右对称，每行由1开始逐渐变大，然后变小，回到1。
        第n行的数字个数为n个。
        第n行的第k个数字为组合数 C_{n-1}^{k-1}。
        第n行数字和为 2^{n-1}。
        除每行最左侧与最右侧的数字以外，每个数字等于它的左上方与右上方两个数字之和（也就是说，第n行第k个数字等于第 n-1 行的第 k-1 个数字与第
        k个数字的和）。这是因为有组合恒等式：C_{n}^{i}=C_{n-1}^{i-1}+C_{n-1}^{i}。可用此性质写出整个杨辉三角形。
        
        由于题目有额外限制条件，程序只能使用 O(k) 的额外空间，那么这样就不能把每行都算出来，而是要用其他的方法, 我最先考虑用的是第三条性质，
        算出每个组合数来生成第n行系数，代码请参见评论区一楼。本地调试输出前十行，没啥问题，拿到 OJ 上测试，程序在第 18 行跪了，中间有个系数
        不正确。那么问题出在哪了呢，仔细找找，原来出在计算组合数那里，由于算组合数时需要算连乘，而整型数 int 的数值范围只有 -32768 到 32768 
        之间，那么一旦n值过大，连乘肯定无法计算。而丧心病狂的 OJ 肯定会测试到成百上千行，所以这个方法不行。那么我们再来考虑利用第五条性质，
        除了第一个和最后一个数字之外，其他的数字都是上一行左右两个值之和。那么我们只需要两个 for 循环，除了第一个数为1之外，后面的数都是上一次
        循环的数值加上它前面位置的数值之和，不停地更新每一个位置的值，便可以得到第n行的数字，具体实现代码如下：
    */
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i; j >= 1; --j) {
                res[j] += res[j - 1];
            }
        }
        return res;
    }
};


class Solution98 {
public:
    // 2023.2.10, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/pascals-triangle-ii.cpp
    // Time:  O(n^2)
    // Space: O(1)
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1);
        for (int i = 0; i < result.size(); ++i) {
            int prev_result = result[0] = 1;
            for (int j = 1; j <= i; ++j) {
                const int tmp = result[j];
                result[j] += prev_result;
                prev_result = tmp;
            }
        }
        return result;
    }
};


class Solution97 {
public:
    // OJ: https://leetcode.com/problems/pascals-triangle-ii/
    // Author: github.com/lzl124631x
    // Time: O(N^2)
    // Space: O(1)
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 1);
        for (int i = 2; i <= rowIndex; ++i) {
            for (int j = i - 1; j > 0; --j) ans[j] += ans[j - 1];
        }
        return ans;
    }
};

class Solution96 {
public:
    // 2023.2.10, from https://walkccc.me/LeetCode/problems/0119/
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 1);

        for (int i = 2; i < rowIndex + 1; ++i)
        for (int j = 1; j < i; ++j)
            ans[i - j] += ans[i - j - 1];

        return ans;
    }
};


class Solution {
public:
    // 2023.2.10, from https://zxi.mytechroad.com/blog/?s=LeetCode+119.
    // Author: huahua
    vector<int> getRow(int rowIndex) {
        vector<int> ans(1, 1);
        for (int i = 2; i <= rowIndex + 1; ++i) {
        vector<int> tmp(i, 1);
        for (int j = 1; j < i - 1; ++j)
            tmp[j] = ans[j] + ans[j - 1];
        swap(ans, tmp);
        }
        return ans;
    }
};


// @lc code=end

