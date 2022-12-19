/*

https://leetcode.cn/problems/missing-element-in-sorted-array/

1060. 有序数组中的缺失元素
现有一个按 升序 排列的整数数组 nums ，其中每个数字都 互不相同 。

给你一个整数 k ，请你找出并返回从数组最左边开始的第 k 个缺失数字。


示例 1：

输入：nums = [4,7,9,10], k = 1
输出：5
解释：第一个缺失数字为 5 。

示例 2：

输入：nums = [4,7,9,10], k = 3
输出：8
解释：缺失数字有 [5,6,8,...]，因此第三个缺失数字为 8 。

示例 3：

输入：nums = [1,2,4], k = 3
输出：6
解释：缺失数字有 [3,5,6,7,...]，因此第三个缺失数字为 6 。
 

提示：

1 <= nums.length <= 5 * 104
1 <= nums[i] <= 107
nums 按 升序 排列，其中所有元素 互不相同 。
1 <= k <= 108
 

进阶：你可以设计一个对数时间复杂度（即，O(log(n))）的解决方案吗？

通过次数9,214提交次数17,248

*/

class Solution100 {
public:
    // 2022.8.7, by Hsinan
    int missingElement(vector<int>& nums, int k) {
        // use stack to push/pop/top the elements
        stack<int> missing;

        for (int i = 0, j = 1; j < nums.size(); i++, j++) {
            int diff = nums[j] - nums[i] - 1;
            if (diff >= 1) {
                for (int index = 0; index < diff; index++) {
                    missing.push(nums[i] + index + 1);
                    if (missing.size() == k) {
                        return missing.top();
                    }
                }
            }
        }
        // not return yet
        return nums[nums.size()-1] + (k - missing.size()); 
    }
};


class Solution99 {
public:
    // 2022.8.7, from https://github.com/wisdompeak/LeetCode/blob/master/Binary_Search/1060.Missing-Element-in-Sorted-Array/1060.Missing-Element-in-Sorted-Array.cpp
    int missingElement(vector<int>& nums, int k) {        
        int left = nums[0];
        int right = nums.back()+k;
        while (left < right)
        {
            int mid = right-(right-left)/2;
            
            int M = mid-nums[0]; // how many nums < mid            
            int T = lower_bound(nums.begin(), nums.end(), mid) - nums.begin(); // how many nums < mid in this array            
            int missing = M - T;
                        
            if (missing > k-1)
                right = mid-1;
            else
                left = mid;            
        }
        
        return left;
    }
};


class Solution98 {
public:
    // 2022.8.7, from https://walkccc.me/LeetCode/problems/1060/
    // Time: O(logn)
    // Space: O(1)
    int missingElement(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size();

        // # of missing numbers in [nums[0], nums[i]]
        auto nMissing = [&](int i) { return nums[i] - nums[0] - i; };

        // find the first index l s.t. nMissing(l) >= k
        while (l < r) {
            const int m = (l + r) / 2;
            if (nMissing(m) >= k)
                r = m;
            else
                l = m + 1;
        }

        return nums[l - 1] + (k - nMissing(l - 1));
    }
};


class Solution97 {
public:
    // 2022.8.7, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/missing-element-in-sorted-array.cpp
    // Time:  O(logn)
    // Space: O(1)
    int missingElement(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {  // find the largest right s.t. k > missingCount(nums, x)
            const auto& mid = left + (right - left) / 2;
            if (!check(nums, k, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return nums[right] + (k - missingCount(nums, right));
    }
    
private:
    int missingCount(const vector<int>& nums, int x) {
        return (nums[x] - nums[0] + 1) - (x - 0 + 1);
    }
    
    bool check(const vector<int>& nums, int k, int x) {
        return k > missingCount(nums, x);
    }
};


/*
    2022.8.7, from https://leetcode.ca/2018-10-25-1060-Missing-Element-in-Sorted-Array/

    Solution
    If the array nums is empty, simply return k since all numbers are missing in nums.

    If k is greater than or equal to the last number in nums, then only the numbers in nums are not 
    missing and all the other numbers are missing, so the k-th missing number is k + nums[0] + nums.length - 1.
    
    Otherwise, starting from the first letter in nums, check each number that is greater, and 
    if a number is not in the array, then it is missing and decrease k by 1. The process ends 
    until the end of nums is reached or k becomes 0. Finally, return the current number plus k.

    class Solution {
        public int missingElement(int[] nums, int k) {
            if (nums == null || nums.length == 0)
                return k;
            int length = nums.length;
            if (k >= nums[length - 1])
                return k + nums[0] + length - 1;
            int num = nums[0];
            int index = 1;
            while (index < length && k > 0) {
                num++;
                if (num == nums[index])
                    index++;
                else
                    k--;
            }
            return num + k;
        }
    }
*/


/************************************************************************************************************/
/************************************************************************************************************/



