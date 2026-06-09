### 解题思路
dp[i]被定义为，以第i个数字结尾的最长升序子序列的长度
dp[i] = max(d[j]+1) (j<i && nums[i]>nums[j])
最后的结果就是max(d[i])
### 代码

```cpp
class Solution {
public:
    //dp[i]被定义为，以第i个数字结尾的最长升序子序列的长度
    //dp[i] = max(d[j]+1) (j<i && nums[i]>nums[j])
    //最后的结果就是max(d[i])
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> dp(n,1);
        for(int i = 0; i < n;i++){
            for(int j = 0; j<i; j++){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[i],dp[j]+1);//如果找到更长的则进行更新
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
```