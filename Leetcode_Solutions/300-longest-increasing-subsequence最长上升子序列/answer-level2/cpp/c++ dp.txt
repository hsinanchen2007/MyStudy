### 解题思路

以nums[i]为当前结尾值，将小于i之前的所有元素与当前进行比较，只有满足严格上升，才会更新。


### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] = max(dp[i-1]+1,dp[i-1])
        int len = nums.size();

        if(len < 2) return len;

        vector<int> dp(len,1);

        for(int i=1;i<len;i++) {
            for(int j=0;j<i;j++) {
                if(nums[j]<nums[i]) {
                    // 自身,前面最大加上自身
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }

        int res=0;
        for(auto elem : dp) {
            res = max(res,elem);
        }
        return res;
    }
};
```