### 解题思路
O(n^2)思路

### 代码

```cpp
const int maxn = 10000+5;
class Solution {
private:
    int dp[maxn];
public:
    int lengthOfLIS(vector<int>& nums) {
        //动态规划
        int len = nums.size();
        if(len<=1) return len;
        int sum = -1;
        for(int i=0;i<len;i++)
        {
            dp[i] = 1;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i]) dp[i] = max(dp[i],dp[j]+1);
            }
            sum = max(sum,dp[i]);
        }
        return sum;
    }
};
```