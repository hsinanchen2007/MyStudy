### 解题思路
一共有n个预约，要求到第n个预约的最大时长。两种情况
1）我们接第n个预约`dp[n]=dp[n-2]+num[n]`。
2）我们不接第n个预约`dp[n]=dp[n-1]`
选时间最大的那个作为dp[n]的值
注意处理边界情况和`dp[0]`,`dp[1]`的赋值

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        //动态规划
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        vector<int>dp(n);
        dp[0]=nums[0];
        dp[1]=max(dp[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};
```
### 优化后的方法

```
class Solution {
public:
    int massage(vector<int>& nums) {
        //动态规划
        int a=0; //a=i-2
        int b=0; //b=i-1
        for(int i=0;i<nums.size();i++){
            int c=max(b,a+nums[i]);
            a=b;
            b=c;
        }
        return b;
    }
};
```