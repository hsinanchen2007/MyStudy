### [题目描述](https://leetcode-cn.com/problems/triangle/)

给定一个无序的整数数组，找到其中最长上升子序列的长度。

#### 样例

```
输入: [10,9,2,5,3,7,101,18]
输出: 4 
解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
```

----------

### 算法1

#### (线性dp)  `时间：O(n^2) & 空间：O(n)`

```
状态表示: dp[i] 以当前数字为结尾的 最长上升子序列
转移方程: dp[i] = max(1, dp[j] + 1), j∈[0, i - 1] && dp[j] < nums[i]
答案所求: dp数组中最大值
```

* 转移方程: 小的数字可以接到比他大的数字的前面. 反过来说以当前数字结尾可以由他前面所有比它小的数字转移过来.

#### C++ 代码

```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        vector<int> dp(n);
        int ans = -1;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }  
        return ans;
    }
};
```

### 算法2

#### (DP + 贪心 + 二分)  `时间：O(nlogn) & 空间：O(n)`

* 状态表示：`dp[i]`表示**长度为i的最长上升子序列，末尾最小的数字**。(长度为i的最长上升子序列所有结尾中，结尾**最小min**的) 即长度为i的子序列末尾最小元素是什么。

* 状态计算：对于每一个`nums[i]`, 如果**大于**`dp[cnt]`(下标从1开始，cnt长度的最长上升子序列，末尾最小的数字)，那就cnt+1，使得最长上升序列长度+1，当前末尾最小元素为`nums[i]`。 若`nums[i]`**小于等于**`dp[cnt]`,说明不会更新当前的长度，但之前末尾的最小元素要发生变化，找到第一个 _大于或等于_ (这里不能是大于) nums[i]，更新以那时候末尾的最小元素。**(第一个大于等于nums[i]的数是可以接在比它小的数的后面的，并且更新最小值还可以维护dp数组非递减的性质)**

* dp[i]一定以一个单调递增的数组，所以可以用**二分法**来找第一个大于或等于dp[i]的数字。

#### C++ 代码

```c++
class Solution {
public:
    // 状态表示: dp[k]表示以k长度的子序列的结尾 最小的数字
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        vector<int> dp(nums.size() + 1);
        int cnt = 1;
        dp[cnt] = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];
            if (x > dp[cnt]) dp[++cnt] = x;
            else {
                auto it = lower_bound(dp.begin() + 1, dp.begin() + cnt, x);
                *it = x;
            }
        }
        
        return cnt;
    }
};
```


