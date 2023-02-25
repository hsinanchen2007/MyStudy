/*

https://leetcode.cn/problems/two-sum-less-than-k/

1099. 小于 K 的两数之和
提示
简单
77
company
亚马逊

给你一个整数数组 nums 和整数 k ，返回最大和 sum ，满足存在 i < j 使得 nums[i] + nums[j] = sum 且 sum < k 。如果没有
满足此等式的 i,j 存在，则返回 -1 。

示例 1：

输入：nums = [34,23,1,24,75,33,54,8], k = 60
输出：58
解释：
34 和 24 相加得到 58，58 小于 60，满足题意。

示例 2：

输入：nums = [10,20,30], k = 15
输出：-1
解释：
我们无法找到和小于 15 的两个元素。 

提示：

1 <= nums.length <= 100
1 <= nums[i] <= 1000
1 <= k <= 2000

*/

class Solution100 {
public:
    // 2023.2.24, from https://walkccc.me/LeetCode/problems/1099/
    // Time: O(n)
    // Space: O(1)
    int twoSumLessThanK(vector<int>& nums, int k) {
        if (nums.size() < 2)
        return -1;

        int ans = -1;  // Note the constraint that nums[i] > 0.
        int l = 0;
        int r = nums.size() - 1;

        sort(begin(nums), end(nums));

        while (l < r)
        if (nums[l] + nums[r] < k) {
            ans = max(ans, nums[l] + nums[r]);
            ++l;
        } else {
            --r;
        }

        return ans;
    }
};


class Solution99 {
public:
    // 2023.2.24, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/two-sum-less-than-k.cpp
    // Time:  O(nlogn)
    // Space: O(1)
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int result = -1;
        int left = 0, right = A.size() - 1;
        while (left < right) {
            if (A[left] + A[right] >= K) {
                --right;
            } else {
                result = max(result, A[left] + A[right]);
                ++left;
            }
        }
        return result;
    }
};


class Solution98 {
public:
    // OJ: https://leetcode.com/problems/two-sum-less-than-k/
    // Author: github.com/lzl124631x
    // Time: O(N)
    // Space: O(1)
    int twoSumLessThanK(vector<int>& A, int k) {
        sort(begin(A), end(A));
        int i = 0, j = A.size() - 1, ans = INT_MIN;
        while (i < j) {
            int sum = A[i] + A[j];
            if (sum < k) {
                ans = max(ans, sum);
                ++i;
            } else --j;
        }
        return ans == INT_MIN ? -1 : ans;
    }
};


class Solution {
public:
    // 作者：xzp
    // 链接：https://leetcode.cn/leetbook/read/sliding-window-and-two-pointers/rwv19h/?discussion=X1kqLn
    // 来源：力扣（LeetCode）
    // 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int twoSumLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int ans = 0 , sum = 0;
        int left = 0 , right = n - 1;
        while(left < right){
            sum = nums[left] + nums[right];
            if(sum >= k) right--;
            else {
                ans = max(sum , ans);
                left++;
            }

        }
        return ans = ans == 0 ? -1 : ans;
    }
};

