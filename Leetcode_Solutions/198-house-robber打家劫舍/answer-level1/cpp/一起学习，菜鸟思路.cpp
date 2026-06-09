由题目可以知道不能同时进入相邻的房子，
设dp[i]表示的是有i间房子时能获得的最大收益，对于第i间房子有偷和不偷两种情况。
如果偷了第i间房子则dp[i] = dp[i-1] + nums[i]
如果不偷第i间房子则dp[i] = dp[i-2]
要收益最大化，故dp[i] = max(dp[i-1]+nums[i], dp[i-2]);

```
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0; //没有房子，偷不到钱
        if(n==1)return nums[0]; //只有一个房子，不能放过

        int *dp = new int[n+5]; //分配空间
        dp[0] = 0 ; //设初始值
        dp[1] = nums[0];
        dp[2] = max(nums[0], nums[1]);

        for(int i=3; i<=n; i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
        }
        return dp[n];
    }
};
```

通过观察整体代码可以发现，数组中只用到了三个变量，故可以不用数组，用三个变量代替即可。
```
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)return 0;
        if(nums.size()==1)return nums[0];
        //状态转移方程 dp[i] = max(dp[i-1], dp[i-2]+nums[i])  
        int dp_i_2=nums[0];
        int dp_i_1=max(nums[0], nums[1]);
        int dp_i = dp_i_1; //一开始赋个初值，避免只有两个房子的情况出现错误。
        int tmp; //用于临时保存变量的值
        for(int i=3; i<=nums.size(); i++){
            dp_i = max(dp_i_1, dp_i_2+nums[i-1]);
            tmp = dp_i_1;
            dp_i_1 = dp_i;
            dp_i_2 = tmp;
        }
        return dp_i;
    }
};
```

