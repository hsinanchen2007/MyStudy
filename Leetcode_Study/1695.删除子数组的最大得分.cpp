/*
 * @lc app=leetcode.cn id=1695 lang=cpp
 *
 * [1695] 删除子数组的最大得分
 */

/*

https://leetcode.cn/problems/maximum-erasure-value/

1695. 删除子数组的最大得分

中等
63
company
微软 Microsoft
company
亚马逊
company
优步 Uber

给你一个正整数数组 nums ，请你从中删除一个含有 若干不同元素 的子数组。删除子数组的 得分 就是子数组各元素之和。
返回只删除一个子数组可获得的 最大得分 。

如果数组 b 是数组 a 的一个连续子序列，即如果它等于 a[l],a[l+1],...,a[r] ，那么它就是 a 的一个子数组。

示例 1：

输入：nums = [4,2,4,5,6]
输出：17
解释：最优子数组是 [2,4,5,6]

示例 2：

输入：nums = [5,2,1,2,5,2,1,2,5]
输出：8
解释：最优子数组是 [5,2,1] 或 [1,2,5]
 
提示：

1 <= nums.length <= 105
1 <= nums[i] <= 104

*/

// @lc code=start
class Solution100 {
public:
    // 2023.2.11, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/maximum-erasure-value.cpp
    // Time:  O(n)
    // Space: O(n)
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> lookup;
        int prefix[size(nums) + 1];
        int result = 0, left = 0;
        for (int right = 0; right < size(nums); ++right) {
            prefix[right + 1] = prefix[right] + nums[right];
            if (lookup.count(nums[right])) {
                left = max(left, lookup[nums[right]] + 1);
            }
            lookup[nums[right]] = right;
            result = max(result, prefix[right + 1] - prefix[left]);
        }
        return result;
    }
};


class Solution99 {
public:
    // OJ: https://leetcode.com/problems/maximum-erasure-value/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(N)
    // Solution 1. Shrinkable Sliding Window + Hash Map
    int maximumUniqueSubarray(vector<int>& A) {
        int i = 0, ans = 0, N = A.size(); // window [i, j] is a window which only contains unique elements.
        unordered_map<int, int> m; // number -> index of last occurrence.
        vector<int> sum(N + 1);
        partial_sum(begin(A), end(A), begin(sum) + 1);
        for (int j = 0; j < N; ++j) {
            if (m.count(A[j])) i = max(i, m[A[j]] + 1);
            m[A[j]] = j;
            ans = max(ans, sum[j + 1] - sum[i]);
        }
        return ans;
    }
};


class Solution98 {
public:
    // OJ: https://leetcode.com/problems/maximum-erasure-value/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(U) where U is the number of unique elements in `A`
    // Solution 2. Shrinkable Sliding Window + Hash Set
    int maximumUniqueSubarray(vector<int>& A) {
        int ans = 0, N = A.size(), sum = 0;
        unordered_set<int> s;
        for (int i = 0, j = 0; j < N; ++j) {
            while (s.count(A[j])) {
                s.erase(A[i]);
                sum -= A[i++];
            }
            s.insert(A[j]);
            sum += A[j];
            ans = max(ans, sum);
        }
        return ans;
    }
};


class Solution97 {
public:
    // OJ: https://leetcode.com/problems/maximum-erasure-value/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(U) where U is the number of unique elements in `A`
    // Solution 3. Shrinkable Sliding Window + Prefix State Map
    int maximumUniqueSubarray(vector<int>& A) {
        int i = 0, j = 0, N = A.size(), ans = 0, dup = 0, sum = 0;
        unordered_map<int, int> cnt;
        while (j < N) {
            dup += ++cnt[A[j]] == 2;
            sum += A[j++];
            while (dup) {
                dup -= --cnt[A[i]] == 1;
                sum -= A[i++];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};


class Solution96 {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // 滑动窗口模板化解题，五步走策略

        // 【1、定义需要维护的变量】

        // 对于此题来说，需要维护当前滑动窗口的元素和、滑动过程中得出的最大得分
        // 一开始，滑动窗口没有元素，元素和为 0 
        int sums = 0;

        // 由于数组都是正数，所以可以初始化为 0
        int largest = 0;

        // 同时又涉及去重，因此需要一个哈希表
        unordered_set<int> hash;

        // 【2、定义窗口的首尾端 (start, end)， 然后滑动窗口】

        // 窗口的左端位置从 0 开始
        int start = 0;

        // 窗口的右端位置从 0 开始，可以一直移动到尾部
        for( int end = 0 ; end < nums.size() ; end++ ){

            // 【3、更新需要维护的变量, 有的变量需要一个 if 语句来维护 (比如最大最小长度)】

            // 【4、如果题目的窗口长度可变: 这个时候一般涉及到窗口是否合法的问题】
            //  如果当前窗口不合法时, 用一个 while 去不断移动窗口左指针, 从而剔除非法元素直到窗口再次合法

            // 如果哈希表中存储了即将加入滑动窗口的元素
            while(hash.count(nums[end])){
                
                // 那么需要不断的把窗口左边的元素移除窗口

                // 元素和需要减去移除的值
                sums -= nums[start];

                // 把 nums[start] 移除记录
                hash.erase(nums[start]);

                // 窗口左端向右移动
                start++;
            }

            // 此时，滑动窗口可以接纳 nums[end]
            hash.insert(nums[end]);

            // 维护变量 sum
            sums += nums[end];

            // 维护变量 largest
            largest = max(largest,sums);

        }

        // 【5、返回所需要的答案】
        return largest;

    }
};


class Solution {
public:
    // 2023.2.11, from https://zxi.mytechroad.com/blog/?s=LeetCode+1695.
    // Author: Huahua
    int maximumUniqueSubarray(vector<int>& nums) {
        const int n = nums.size();
        unordered_set<int> t;
        int ans = 0;
        for (int l = 0, r = 0, s = 0; r < n; ++r) {
            while (t.count(nums[r]) && l < r) {
                s -= nums[l];
                t.erase(nums[l++]);
            }      
            t.insert(nums[r]);
            ans = max(ans, s += nums[r]);
        }
        return ans;
    }
};


// @lc code=end

