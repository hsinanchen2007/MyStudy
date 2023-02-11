/*
 * @lc app=leetcode.cn id=1493 lang=cpp
 *
 * [1493] 删掉一个元素以后全为 1 的最长子数组
 */

/*

https://leetcode.cn/problems/longest-subarray-of-1s-after-deleting-one-element/

1493. 删掉一个元素以后全为 1 的最长子数组

中等
72
company
阿里巴巴
company
苹果 Apple
company
字节跳动

给你一个二进制数组 nums ，你需要从中删掉一个元素。

请你在删掉元素的结果数组中，返回最长的且只包含 1 的非空子数组的长度。
如果不存在这样的子数组，请返回 0 。

提示 1：

输入：nums = [1,1,0,1]
输出：3
解释：删掉位置 2 的数后，[1,1,1] 包含 3 个 1 。

示例 2：

输入：nums = [0,1,1,1,0,1,1,0,1]
输出：5
解释：删掉位置 4 的数字后，[0,1,1,1,1,1,0,1] 的最长全 1 子数组为 [1,1,1,1,1] 。

示例 3：

输入：nums = [1,1,1]
输出：2
解释：你必须要删除一个元素。 

提示：

1 <= nums.length <= 105
nums[i] 要么是 0 要么是 1 。

*/

// @lc code=start
class Solution100 {
public:
    // 2023.2.11, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/longest-subarray-of-1s-after-deleting-one-element.cpp
    // Time:  O(n)
    // Space: O(1)
    int longestSubarray(vector<int>& nums) {
        int count = 0, left = 0, right = 0;
        for (; right < nums.size(); ++right) {
            count += (nums[right] == 0);
            if (count >= 2) {
                count -= (nums[left++] == 0);
            }
        }
        return (right - left) - 1;
    }
};


class Solution99 {
public:
    // 2023.2.11, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/longest-subarray-of-1s-after-deleting-one-element.cpp
    // Time:  O(n)
    // Space: O(1)
    int longestSubarray(vector<int>& nums) {
        int result = 0, count = 0, left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            count += (nums[right] == 0);
            while (count >= 2) {
                count -= (nums[left++] == 0);
            }
            result = max(result, right - left + 1);
        }
        return result - 1;
    }
};


class Solution98 {
public:
    // OJ: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    /*
        Solution 1.
        prev2 and prev are the indexes of the non-one values we've seen most recently during scanning.

        prev2              prev            i
        0       1 1 1      0      1 1 1    0 
        If the array only contains 1, then return N - 1. Otherwise, the answer is the maximum of i - prev2 - 2.    
    */
    int longestSubarray(vector<int>& A) {
        int N = A.size(), prev2 = -1, prev = -1, ans = 0;
        for (int i = 0; i <= N; ++i) {
            if (i < N && A[i] == 1) continue;
            if (i == N && prev == -1) return N - 1;
            if (prev != -1) ans = max(ans, i - prev2 - 2);
            prev2 = prev;
            prev = i;
        }
        return ans;
    }
};


class Solution97 {
public:
    // OJ: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    // Shrinkable Sliding Window
    int longestSubarray(vector<int>& A) {
        int i = 0, j = 0, N = A.size(), cnt = 0, ans = 0;
        for (; j < N; ++j) {
            cnt += A[j] == 0;
            while (cnt > 1) cnt -= A[i++] == 0;
            ans = max(ans, j - i);
        }
        return ans;
    }
};


class Solution96 {
public:
    // OJ: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    // Non-shrinkable Sliding Window
    int longestSubarray(vector<int>& A) {
        int i = 0, j = 0, N = A.size(), cnt = 0;
        for (; j < N; ++j) {
            cnt += A[j] == 0;
            if (cnt > 1) cnt -= A[i++] == 0;
        }
        return j - i - 1;
    }
};


class Solution95 {
public:
    // 2023.2.11, from https://zxi.mytechroad.com/blog/?s=LeetCode+1493
    // Author: Huahua
    /*
        Solution 1: DP

        Preprocess:
        l[i] := longest 1s from left side ends with nums[i], l[i] = nums[i] + nums[i] * l[i – 1]
        r[i] := longest 1s from right side ends with nums[i], r[i] = nums[i] + nums[i] * r[i + 1]

        Use each node as a bridge (ignored), the total number of consecutive 1s = l[i – 1] + r[i + 1].

        ans = max{l[i-1] + r[i +1]}

        Time complexity: O(n)
        Space complexity: O(n)    
    */
    int longestSubarray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> l(n);
        vector<int> r(n);
        for (int i = 0; i < n; ++i)
        l[i] = (i > 0 ? l[i - 1] * nums[i] : 0) + nums[i];
        for (int i = n - 1; i >= 0; --i)
        r[i] = (i < n - 1 ? r[i + 1] * nums[i] : 0) + nums[i];
        int ans = 0;
        for (int i = 0; i < n; ++i)
        ans = max(ans, (i > 0 ? l[i - 1] : 0) + 
                        (i < n - 1 ? r[i + 1] : 0));
        return ans;
    }
};


class Solution94 {
public:
    // 2023.2.11, from https://zxi.mytechroad.com/blog/?s=LeetCode+1493
    // Author: Huahua
    /*
        Solution 2: DP

        dp[i][0] := longest subarray ends with nums[i] has no ones.
        dp[i][0] := longest subarray ends with nums[i] has 1 one.
        if nums[i] == 1:
        dp[i][0] = dp[i – 1][0] + 1
        dp[i][1] = dp[i – 1][1] + 1
        if nums[i] == 0:
        dp[i][0] = 0
        dp[i][1] = dp[i – 1][0] + 1

        Time complexity: O(n)
        Space complexity: O(n) -> O(1)
    */
    int longestSubarray(vector<int>& nums) {
        const int n = nums.size();
        // dp[i][0] := longest subarray ends with nums[i-1] has no zeros.
        // dp[i][0] := longest subarray ends with nums[i-1] has 1 zero.
        vector<vector<int>> dp(n + 1, vector<int>(2));
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
        if (nums[i - 1] == 1) {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1] + 1;
        } else {
            dp[i][0] = 0;
            dp[i][1] = dp[i - 1][0] + 1;
        }
        ans = max({ans, dp[i][0] - 1, dp[i][1] - 1});
        }
        return ans;
    }
};


class Solution {
public:
    // 2023.2.11, from https://zxi.mytechroad.com/blog/?s=LeetCode+1493
    // Author: Huahua
    /*
        Solution 3: Sliding Window

        Maintain a sliding window l ~ r s.t sum(num[l~r]) >= r – l. There can be at most one 0 in the window.
        ans = max{r – l} for all valid windows.

        Time complexity: O(n)
        Space complexity: O(1)    
    */
    int longestSubarray(vector<int>& nums) {
        const int n = nums.size();
        int ans = 0;
        int sum = 0; // sum of nums[l~r].
        for (int l = 0, r = 0; r < n; ++r) {
        sum += nums[r];
        // Maintain sum >= r - l, at most 1 zero.
        while (l < r && sum < r - l)
            sum -= nums[l++];
        ans = max(ans, r - l);
        }
        return ans;
    }
};

// @lc code=end

