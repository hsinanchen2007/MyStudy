/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */

/*

https://leetcode.cn/problems/maximum-average-subarray-i/

643. 子数组最大平均数 I
给你一个由 n 个元素组成的整数数组 nums 和一个整数 k 。

请你找出平均数最大且 长度为 k 的连续子数组，并输出该最大平均数。

任何误差小于 10-5 的答案都将被视为正确答案。
 

示例 1：

输入：nums = [1,12,-5,-6,50,3], k = 4
输出：12.75
解释：最大平均数 (12-5-6+50)/4 = 51/4 = 12.75

示例 2：

输入：nums = [5], k = 1
输出：5.00000
 

提示：

n == nums.length
1 <= k <= n <= 105
-104 <= nums[i] <= 104
通过次数87,088提交次数195,808

*/

// @lc code=start
class Solution100 {
public:
    // 2022.8.13, by Hsinan
    double findMaxAverage(vector<int>& nums, int k) {
        double max = -1000000.0;
        double sum = 0;
        double start = 0;
        for (int end = 0; end < nums.size(); end++) {
            sum += nums[end];
            if (end + 1 >= k) {
                max = std::max(max, sum);
                sum -= nums[start];
                start++;
            }
        }
        return (max / k);
    }
};


class Solution99 {
public:
    // 2022.8.13, from https://www.acwing.com/activity/content/code/content/638210/
    // 作者：yxc
    // 链接：https://www.acwing.com/activity/content/code/content/638210/
    // 来源：AcWing
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    double findMaxAverage(vector<int>& nums, int k) {
        double res = -1e5;
        for (int i = 0, j = 0, s = 0; i < nums.size(); i ++ ) {
            s += nums[i];
            if (i - j + 1 > k) s -= nums[j ++ ];
            if (i >= k - 1) res = max(res, s / (double)k);
        }
        return res;
    }
};


class Solution98 {
public:
    // 2022.8.13, from https://github.com/grandyang/leetcode/issues/643
    /*
        这道题给了我们一个数组nums，还有一个数字k，让我们找长度为k且平均值最大的子数组。由于子数组必须是连续的，
        所以我们不能给数组排序。那么怎么办呢，在博主印象中，计算子数组之和的常用方法应该是建立累加数组，然后我们
        可以快速计算出任意一个长度为k的子数组，用来更新结果res，从而得到最大的那个，参见代码如下：
    */
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums = nums;
        for (int i = 1; i < n; ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }
        double mx = sums[k - 1];
        for (int i = k; i < n; ++i) {
            mx = max(mx, (double)sums[i] - sums[i - k]);
        }
        return mx / k;
    }
};


class Solution97 {
public:
    // 2022.8.13, from https://github.com/grandyang/leetcode/issues/643
    /*
        由于这道题子数组的长度k是确定的，所以我们其实没有必要建立整个累加数组，而是先算出前k个数字的和，然后就像维护
        一个滑动窗口一样，将窗口向右移动一位，即加上一个右边的数字，减去一个左边的数字，就等同于加上右边数字减去左边
        数字的差值，然后每次更新结果res即可，参见代码如下：
    */
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = accumulate(nums.begin(), nums.begin() + k, 0), res = sum;
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i] - nums[i - k];
            res = max(res, sum);
        }
        return res / k;
    }
};


class Solution96 {
public:
    // 2022.8.13, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/maximum-average-subarray-i.cpp
    // Time:  O(n)
    // Space: O(1)
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        double result = sum;
        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i] - nums[i-k];
            result = max(result, sum);
        }
        return result / k;
    }
};


class Solution95 {
public:
    // 2022.8.13, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/643.%20Maximum%20Average%20Subarray%20I
    // OJ: https://leetcode.com/problems/maximum-average-subarray-i/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0, maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < k) {
                sum += nums[i];
                if (i == k - 1) maxSum = sum;
            } else {
                sum += nums[i] - nums[i - k];
                maxSum = max(maxSum, sum);
            }
        }
        return (double)maxSum / k;
    }
};


class Solution {
public:
    // 2022.8.13, from https://walkccc.me/LeetCode/problems/0643/
    // Time: O(n)
    // Space: O(1)
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = accumulate(begin(nums), begin(nums) + k, 0);
        double ans = sum;

        for (int i = k; i < nums.size(); ++i) {
            sum += nums[i] - nums[i - k];
            ans = max(ans, sum);
        }

        return ans / k;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// 2022.8.15, not in top list

// @lc code=end

