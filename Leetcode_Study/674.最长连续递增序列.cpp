/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

/*

https://leetcode.cn/problems/longest-continuous-increasing-subsequence/

674. 最长连续递增序列

简单
356
company
Facebook
company
谷歌 Google
给定一个未经排序的整数数组，找到最长且 连续递增的子序列，并返回该序列的长度。

连续递增的子序列 可以由两个下标 l 和 r（l < r）确定，如果对于每个 l <= i < r，都有 nums[i] < nums[i + 1] ，那么子序列 
[nums[l], nums[l + 1], ..., nums[r - 1], nums[r]] 就是连续递增子序列。 

示例 1：

输入：nums = [1,3,5,4,7]
输出：3
解释：最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为 5 和 7 在原数组里被 4 隔开。 

示例 2：

输入：nums = [2,2,2,2,2]
输出：1
解释：最长连续递增序列是 [2], 长度为1。 

提示：

1 <= nums.length <= 104
-109 <= nums[i] <= 109

*/

// @lc code=start
class Solution100 {
public:
    // 2023.2.2 from https://github.com/youngyangyang04/leetcode-master/blob/master/problems/0674.%E6%9C%80%E9%95%BF%E8%BF%9E%E7%BB%AD%E9%80%92%E5%A2%9E%E5%BA%8F%E5%88%97.md
    // 时间复杂度：O(n)
    // 空间复杂度：O(1)
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int result = 1; // 连续子序列最少也是1
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) { // 连续记录
                count++;
            } else { // 不连续，count从头开始
                count = 1;
            }
            if (count > result) result = count;
        }
        return result;
    }
};


class Solution99 {
public:
    // 2023.2.2 from https://ke.algomooc.com/p/t_pc/course_pc_detail/video/v_628a513be4b01c509ab3e309?product_id=p_628a35d3e4b0812e179cf4bc&content_app_id=&type=8&parent_pro_id=p_6243bcc1e4b04e8d90291891
    int findLengthOfLCIS(vector<int>& nums) {
        // 设置数组 dp，用来存储 nums 中以每个元素结尾的最长连续递增序列的程度
        // dp[0] 表示以 nums[0] 结尾的最长连续递增序列的长度
        // dp[1] 表示以 nums[1] 结尾的最长连续递增序列的长度
        // dp[i] 表示以 nums[i] 结尾的最长连续递增序列的长度
        // 首先将数组 dp 里面的值都初始化为 1
        // 1 表示以当前元素结尾的最长连续递增序列的长度为 1
        // 即最长连续递增序列就是当前元素本身
        vector<int> dp( nums.size() , 1 );

        // 设置一个变量用来存储最长连续递增序列的结果
        int maxLength = 1;

        // 从 1 开始，直到 dp.length ，往 dp 里面填充结果
        for(int i = 1 ; i < dp.size() ; i++){
            // 索引      0  1  2  3  4  5  6
            // nums 为 [ 1, 5, 2, 5, 3, 7, 2 ]
            // 此时 i 为 3，那么 1,5,2 这些数字都在索引位置为 3 的前面
            // 此时发现 i - 1 对应的数字为 2
            // nums[i ] > nums[ i - 1 ]，意味着最长连续递增序列的长度增加了
            // 需要更新 dp[i]
            if(nums[i] > nums[ i - 1 ]){
                // 4、更新 dp[i]
                dp[i] = dp[ i - 1] + 1;
            }

            // 在更新 dp[i] 的过程中，发现了一个更长的子序列
            if(maxLength < dp[i]){
                // 那么把更长的子序列的长度赋值给 maxLength
                maxLength = dp[i];
            }
        }

        // 最后返回 maxLength 就行
        return maxLength;
    }
};


class Solution98 {
public:
    // 2023.2.2 from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/674.%20Longest%20Continuous%20Increasing%20Subsequence
    // OJ: https://leetcode.com/problems/longest-continuous-increasing-subsequence/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0, len = 0, prev = INT_MAX;
        for (int n : nums) {
            if (n > prev) ++len;
            else len = 1;
            prev = n;
            ans = max(ans, len);
        }
        return ans;
    }
};


class Solution97 {
public:
    // 2023.2.2 from https://walkccc.me/LeetCode/problems/0674/
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0;

        for (int l = 0, r = 0; r < nums.size(); ++r) {
        if (r > 0 && nums[r] <= nums[r - 1])
            l = r;
        ans = max(ans, r - l + 1);
        }

        return ans;
    }
};


class Solution {
public:
    // 2023.2.2 from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/longest-continuous-increasing-subsequence.cpp
    // Time:  O(n)
    // Space: O(1)
    int findLengthOfLCIS(vector<int>& nums) {
        int result = 0, count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i - 1] < nums[i]) {
                result = max(result, ++count);
            } else {
                count = 1;
            }
        }
        return result;
    }   
};


// @lc code=end

