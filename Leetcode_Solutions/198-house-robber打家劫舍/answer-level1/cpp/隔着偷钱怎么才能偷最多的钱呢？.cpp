### 解题思路
花了我2个小时的时间，因为一个不知道是什么的错误Error29，最后发现是数组越界了，nums和dp数组的序号是错位的，一定要细心才行呀。
状态方程：
f(n)=max(f(n-2)+这第n家的钱, f(n-1))
初始状态：f(0)=0, f(1)=第1家的钱

### 代码

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        int dp[n+1];
        dp[0]=0, dp[1]=nums[0];
        for(int i=2; i<=n; i++){
            dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
        }
        return dp[n];
    }
};
```