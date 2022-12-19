/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于 K 的子数组
 */

/*

https://leetcode.cn/problems/subarray-product-less-than-k/

713. 乘积小于 K 的子数组
给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
 

示例 1：

输入：nums = [10,5,2,6], k = 100
输出：8
解释：8 个乘积小于 100 的子数组分别为：[10]、[5]、[2],、[6]、[10,5]、[5,2]、[2,6]、[5,2,6]。
需要注意的是 [10,5,2] 并不是乘积小于 100 的子数组。

示例 2：

输入：nums = [1,2,3], k = 0
输出：0
 

提示: 

1 <= nums.length <= 3 * 104
1 <= nums[i] <= 1000
0 <= k <= 106
通过次数85,721提交次数175,317

*/

// @lc code=start
class Solution100 {
public:
    // 2022.9.15, from https://www.acwing.com/activity/content/code/content/974875/
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int res = 0, p = 1;
        for (int i = 0, j = 0; i < nums.size(); i ++ ) {
            p *= nums[i];
            while (j <= i && p >= k) p /= nums[j ++ ];
            res += i - j + 1;
        }
        return res;
    }
};


class Solution99 {
public:
    // 2022.9.15, from https://github.com/grandyang/leetcode/issues/713
    /*
        这道题给了我们一个数组和一个数字K，让求子数组且满足乘积小于K的个数。既然是子数组，那么必须是连续的，
        所以肯定不能给数组排序了，这道题好在限定了输入数字都是正数，能稍稍好做一点。博主刚开始用的是暴力搜索
        的方法来做的，就是遍历所有的子数组算乘积和K比较，两个 for 循环就行了，但是 OJ 不答应。于是上网搜
        大神们的解法，思路很赞。相当于是一种滑动窗口的解法，维护一个数字乘积刚好小于k的滑动窗口，用变量 left 
        来记录其左边界的位置，右边界i就是当前遍历到的位置。遍历原数组，用 prod 乘上当前遍历到的数字，然后
        进行 while 循环，如果 prod 大于等于k，则滑动窗口的左边界需要向右移动一位，删除最左边的数字，那么
        少了一个数字，乘积就会改变，所以用 prod 除以最左边的数字，然后左边右移一位，即 left 自增1。当确定
        了窗口的大小后，就可以统计子数组的个数了，就是窗口的大小。为啥呢，比如 [5 2 6] 这个窗口，k还是 100，
        右边界刚滑到6这个位置，这个窗口的大小就是包含6的子数组乘积小于k的个数，即 [6], [2 6], [5 2 6]，
        正好是3个。所以窗口每次向右增加一个数字，然后左边去掉需要去掉的数字后，窗口的大小就是新的子数组的个数，
        每次加到结果 res 中即可，参见代码如下：
    */
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int res = 0, prod = 1, left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            prod *= nums[i];
            while (left <= i && prod >= k) prod /= nums[left++];
            res += i - left + 1;
        }
        return res;
    }
};


class Solution98 {
public:
    // 2022.9.15, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/subarray-product-less-than-k.cpp
    // Time:  O(n)
    // Space: O(1)
    // Sliding window solution.
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int result = 0, start = 0, prod = 1;
        for (int i = 0; i < nums.size(); ++i) {
            prod *= nums[i];
            while (prod >= k) {
                prod /= nums[start];
                ++start;
            }
            result += i - start + 1;
        }
        return result;
    }
};


class Solution97 {
public:
    // 2022.9.15, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/713.%20Subarray%20Product%20Less%20Than%20K
    // OJ: https://leetcode.com/problems/subarray-product-less-than-k/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    int numSubarrayProductLessThanK(vector<int>& A, int k) {
        if (k == 0) return 0;
        long i = 0, j = 0, N = A.size(), prod = 1, ans = 0;
        for (; j < N; ++j) {
            prod *= A[j];
            while (i <= j && prod >= k) prod /= A[i++];
            ans += j - i + 1;
        }
        return ans;
    }
};


class Solution96 {
public:
    // 2022.9.15, from https://walkccc.me/LeetCode/problems/0713/
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1)
        return 0;

        int ans = 0;
        int prod = 1;

        for (int l = 0, r = 0; r < nums.size(); ++r) {
            prod *= nums[r];
            while (prod >= k)
                prod /= nums[l++];
            ans += r - l + 1;
        }

        return ans;
    }
};


class Solution {
public:
    // 2022.9.15, from https://github.com/wisdompeak/LeetCode/blob/master/Two_Pointers/713.Subarray-Product-Less-Than-K/713.Subarray-Product-Less-Than-K.cpp
    /*
        713.Subarray-Product-Less-Than-K
        本题有很明显的滑窗的特征，所以基本思路是用双指针。保证一个乘积小于k的最大窗口，这个窗口内可以构成subarray的数目就是j-i+1;

        本题需要注意的一点是，当nums[i]>k时，右指针动不了，而左指针依然会顺移，所以可能会出现j<i的情况，此时只需要重置这两个指针即可：

        if (j<i)
        {
            j = i;
            product = 1;
        }
    */
    int numSubarrayProductLessThanK(vector<int>& nums, int k) 
    {
        if (k<=1) return 0;
        int j=0;
        int prod = 1;
        int count = 0;
        for (int i=0; i<nums.size(); i++)
        {            
            if (j<i)
            {
                j = i;
                prod = 1;
            }
            
            while (j<nums.size() && prod*nums[j]<k)
            {
                prod = prod*nums[j];
                j++;
            }
            count += j-i;
            prod = prod/nums[i];
        }
        return count;
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


// @lc code=end

