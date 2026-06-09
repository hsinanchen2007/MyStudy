### 解题思路：动态规划
1. 数组记录前i个数字的最长上升子序列长度（初始化为1）
2. 状态转移：dp[i] = max(dp[i], dp[j]+1)  其中0≤j<i且满足nums[j]<nums[i]
3. 动态更新最长子序列
时间复杂度：O(n^2)

### 代码
```cpp
class Solution {
    // DP
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)  return 0;  // 特殊情况，列表为空
        int n = nums.size();
        vector<int> max_len(n, 1);   //记录前i个数字的最长上升子序列长度（初始化为1）
        int res = 1;   // 返回结果（最小为1）
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                // 满足条件nums[j]<nums[i]
                if(nums[j]<nums[i])
                    max_len[i] = max(max_len[i], max_len[j]+1) ;  // 状态转移：dp[i] = max(dp[i], dp[j]+1)
            }
            res = max(res, max_len[i]);  //更新最长子序列长度
        }
        return res;
    }
};
```