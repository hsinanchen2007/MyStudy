## 思路一
动态规划，用dp[i]表示以i结尾的最大子序列和。初始值 dp[0] = nums[0]，然后从第二个数开始遍历
- if 当前数加上前一个最大序列和大于当前数，则将当前数加到序列和中，nums[i] + dp[i-1] > nums[i]，则 dp[i] = nums[i] + dp[i-1];
- else 以当前数结尾的最大序列和即为当前数本身 dp[i] = nums[i]

然后判断以当前数结尾的最大序列和是否大于最大序列和。

### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();        
        int max = nums[0];
        int dp[size];
        dp[0] = nums[0];
        for (int i = 1; i < size; ++i) {
            if (nums[i] + dp[i-1] >= nums[i]) {
                dp[i] = nums[i] + dp[i-1];
            } else {
                dp[i] = nums[i];                
            }
            if (dp[i] > max) {
                max = dp[i];
            }
        }
        return max;
    }
};
```
#### 优化空间
因为以当前数结尾的最大序列和仅与前一个序列和相关，所以可以用一个变量保存。
```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();        
        int max = nums[0];   
        int pre = nums[0];
        for (int i = 1; i < size; ++i) {
            if (nums[i] + pre >= nums[i]) {
                pre = nums[i] + pre;
            } else {
                pre = nums[i];                
            }
            if (pre > max) {
                max = pre;
            }
        }
        return max;
    }
};
```
#### 代码化简
```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int res = INT_MIN;
        for (int a : nums) {
            curSum = max(curSum+a, a);
            res = max(curSum, res);
        }
        return res;
    }
};
```
