### 解题思路
动态规划思想
dp[i] 存储遍历到第i个元素时，连续序列的长度
dp[0]=1
dp[i]= dp[i-1] + 1 || dp[i-1] || 1

唯一需要注意的是，出现重复元素的时候，也就是else if的时候。dp[i]=dp[i-1]

执行用时 :8 ms, 在所有 cpp 提交中击败了97.91%的用户
内存消耗 :9.1 MB, 在所有 cpp 提交中击败了92.97%的用户

### 代码

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return size;
        }
        sort(nums.begin(), nums.end());
        // dp[i] 动态规划
        vector<int> dp(size, 0);
        int max = 1;
        dp[0] = 1;
        for (int i = 1; i < size; ++i) {
            if(nums[i] == nums[i-1] + 1) {
                //连续递增
                dp[i] = dp[i-1] + 1;
            } else if(nums[i] == nums[i-1]) {
                dp[i] = dp[i-1];
            } else {
                dp[i] = 1;
            }
            if (dp[i] > max) {
                max = dp[i];
            }
        }
        return max;
    }
};
```