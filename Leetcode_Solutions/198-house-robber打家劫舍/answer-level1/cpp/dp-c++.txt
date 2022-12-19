开始的dp思路有问题，虽然我做出来了：

dp数组含义：dp[i]表示以i号房为尾能偷盗的最多金额

方程：$dp[i]=nums[i-1]+max(dp[j]|j<(i-1))$

base case: dp[0] = 0, dp[1] = A[0], dp[2] = max(A[0], A[1])

代码如下：

```c++
class Solution {
public:
    //之前那种简单的间隔思想是错的，比如[1000,1,1,1000]就不适用
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        vector<int> dp(n + 1);
        //base case:
        dp[0] = 0, dp[1] = nums[0], dp[2] = max(nums[0], nums[1]);
        int ans = dp[2];  //这样ans是前3个最大的
        for(int i = 3; i <= n; i++) {
            int temp = dp[i - 2];
            for(int j = i - 2; j >= 1; j--) {
                temp = max(dp[j], temp);
            }
            dp[i] = nums[i - 1] + temp;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```


后来参考别人的代码，这么做会更好：

dp数组含义：dp[i]代表前i号房（包括i号房）可以偷到的最多金额

所以有方程：$dp[i]=max(dp[i-1], dp[i-2] + nums[i-1])$

**意思是偷了前一家啥也不做，所以dp[i] == dp[i-1],亦或是要偷这一家，将其与dp[i-2]相加（不能是dp[i-1]是因为无法保证前一家未被偷）**

所以有base case: dp[0] = 0, dp[1] =nums[1]

代码如下：

```c++
class Solution {
public:
    //之前那种简单的间隔思想是错的，比如[1000,1,1,1000]就不适用
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int> dp(n + 1);
        dp[0] = 0, dp[1] = nums[0];  //base case
        for(int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[n];
        
    }
};
```

显然更快。。




