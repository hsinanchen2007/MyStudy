/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续 1 的个数
 */

/*

https://leetcode.cn/problems/max-consecutive-ones/

485. 最大连续 1 的个数

简单
366
company
谷歌 Google
给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。

示例 1：

输入：nums = [1,1,0,1,1,1]
输出：3
解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.

示例 2:

输入：nums = [1,0,1,1,0,1]
输出：2
 
提示：

1 <= nums.length <= 105
nums[i] 不是 0 就是 1.

*/

// @lc code=start
class Solution100 {
public:
    // 2023.2.2, by Hsinan
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = -1, right = -1;
        int size = nums.size();
        int max = 0;
        if (size == 0) return 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] == 1) {
                if (left == -1) {
                    left = i;
                } else {
                    right = i;
                }
            } else {
                if (left != -1 && right == -1) {
                    // only one 1 before
                    right = i;
                    max = std::max(max, right - left);
                    left = -1;
                    right = -1;
                } else if (left != -1 && right != -1) {
                    // multiple 1 before
                    max = std::max(max, right - left + 1);
                    left = -1;
                    right = -1;                                        
                }
            }
        }
        if (left != -1 && right == -1) {
            max = std::max(max, 1);
            left = -1;
            right = -1;           
        } else if (left != -1 && right != -1) {
            // 1 to at the end
            max = std::max(max, right - left + 1);
            left = -1;
            right = -1;                
        }

        return max;
    }
};


class Solution {
public:
    // 2023.2.2, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/485.%20Max%20Consecutive%20Ones
    // OJ: https://leetcode.com/problems/max-consecutive-ones/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    int findMaxConsecutiveOnes(vector<int>& A) {
        int ans = 0, cnt = 0;
        for (int n : A) {
            if (n) ans = max(ans, ++cnt);
            else cnt = 0;
        }
        return ans;
    }
};


// @lc code=end

