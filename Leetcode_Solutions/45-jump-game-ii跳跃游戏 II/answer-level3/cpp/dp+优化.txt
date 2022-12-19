### 解题思路
简单dp+优化。
1.dp思想是，当前的最短路径，取决于所有能到达此处的路径中最短的一个。

2.没有数据范围，但是直接用上述思想会发现TLE，因此思考后，可以发现，如果前一个位置能到达某位置，那么当前位置如果能跳跃的小于前一个位置，就已经不可能比前一个位置路径更短了。

### 代码

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,INT_MAX);
        dp[0]=0;
        for(int i=0;i<n;i++){
            if(i>0&&nums[i]<nums[i-1]) continue;
            for(int j=1;j<=nums[i];j++){
                int k=i+j;
                if(k<=n-1) dp[k]=min(dp[k],dp[i]+1);
            }
        }
        return dp[n-1];
    }
};
```