/* 

https://leetcode.cn/problems/3sum-smaller/

259. 较小的三数之和
给定一个长度为 n 的整数数组和一个目标值 target ，寻找能够使条件 nums[i] + nums[j] + nums[k] < target 成立的三元组  i, j, k 个数（0 <= i < j < k < n）。
 

示例 1：

输入: nums = [-2,0,1,3], target = 2
输出: 2 
解释: 因为一共有两个三元组满足累加和小于 2:
     [-2,0,1]
     [-2,0,3]

示例 2：

输入: nums = [], target = 0
输出: 0 

示例 3：

输入: nums = [0], target = 0
输出: 0 
 

提示:

n == nums.length
0 <= n <= 3500
-100 <= nums[i] <= 100
-100 <= target <= 100
通过次数10,005提交次数17,904

*/

class Solution100 {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        // sanity check if nums didn't have enough numbers
        if (nums.size() < 3) return 0;
    
        // define return and sort vector first
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());

        // iterate from i
        for (int i = 0; i < n - 2; ++i) {
            // define two pointers
            int left = i + 1, right = n - 1;

            // when left < right
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] < target) {
                    // tricky, use (right -left) to get all valid solutions
                    res += right - left;
                    ++left;
                } else {
                    // no valid solution here
                    --right;
                }
            }
        }

        return res;
    }
};


class Solution99 {
public:
    // 2022.6.12, from https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/3sum-smaller.cpp
    // Time:  O(n^2)
    // Space: O(1)
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();

        int count = 0;
        for (int k = 2; k < n; ++k) {
            int i = 0, j = k - 1;
            while (i < j) {  // Two Pointers, linear time.
                if (nums[i] + nums[j] + nums[k] >= target) {
                    --j;
                } else {
                    count += j - i;
                    ++i;
                }
            }
        }

        return count;
    }
};


class Solution98 {
private:
    // 2022.7.27, from https://github.com/lzl124631x/LeetCode/tree/master/leetcode/259.%203Sum%20Smaller
    // OJ: https://leetcode.com/problems/3sum-smaller/
    // Author: github.com/lzl124631x
    // Time: O(N^2)
    // Space: O(1)
    int twoSumSmaller(vector<int>& nums, int start, int target) {
        int i = start, j = nums.size() - 1, ans = 0;
        while (i < j) {
            if (nums[i] + nums[j] < target) {
                ans += j - i;
                ++i;
            } else --j;
        }
        return ans;
    }
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int N = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < N; ++i) 
            ans += twoSumSmaller(nums, i + 1, target - nums[i]);
        return ans;
  ß  }
};


class Solution97 {
public:
    // 2022.7.27, from https://walkccc.me/LeetCode/problems/0259/
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3)
        return 0;

        int ans = 0;

        sort(begin(nums), end(nums));

        for (int i = 0; i + 2 < nums.size(); ++i) {
        int l = i + 1;
        int r = nums.size() - 1;
        while (l < r)
            if (nums[i] + nums[l] + nums[r] < target) {
            // (nums[i], nums[l], nums[r])
            // (nums[i], nums[l], nums[r - 1])
            // ...,
            // (nums[i], nums[l], nums[l + 1])
            ans += r - l;
            ++l;
            } else {
            --r;
            }
        }

        return ans;
    }
};


class Solution96 {
public:
    // 2022.7.27, from https://github.com/MaskRay/LeetCode/blob/master/3sum-smaller.cc
    int threeSumSmaller(vector<int>& a, int target) {
        int n = a.size(), r = 0;
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
        int j = i+1, k = n-1;
        for (; j < n; j++) {
            for (; j < k && a[i]+a[j]+a[k] >= target; k--);
            if (j < k)
            r += k-j;
        }
        }
        return r;
    }
};


class Solution {
public:
    // 2022.7.27, from https://github.com/wisdompeak/LeetCode/blob/master/Two_Pointers/259.3Sum-Smaller/259.%203Sum%20Smaller.cpp
    int threeSumSmaller(vector<int>& nums, int target) 
    {
        int count=0;
        sort(nums.begin(),nums.end());
        
        for (int a=0; a<nums.size(); a++)
        {
            int sum=target-nums[a];
            int left=a+1;
            int right=nums.size()-1;
            
            while (left<right)
            {
                if (nums[left]+nums[right]<sum)
                {
                    count+=right-left;
                    left++;
                }
                else
                {
                    right--;
                }
            }
            
            //cout<<count<<endl;
        }
        
        return count;
        
    }
};


/************************************************************************************************************/
/************************************************************************************************************/


