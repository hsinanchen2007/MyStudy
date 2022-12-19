dp[n][2]保存每个位置可以得到的最大和最小的数值

每个位置上的最大值
dp[i+1][0]=max(dp[i][0]*nums[i],dp[i][1]*nums[i],nums[i])
最小值类似

res保存过程中得到的最大的乘积

代码如下：
```
public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];

        int dp[n + 1][2];
        memset(dp, 0, sizeof(dp));
        dp[0][1] = 1;
        int res = nums[0];
        for (int i = 0; i < n; i++) {
            int p1 = dp[i][0] * nums[i];
            int p2 = dp[i][1] * nums[i];
            dp[i + 1][0] = max(nums[i], max(p1, p2));
            dp[i + 1][1] = min(nums[i], min(p1, p2));
            res = max(res, max(dp[i + 1][0], dp[i + 1][1]));
        }
        return res;
    }
```

执行用时4ms
![image.png](https://pic.leetcode-cn.com/23841a70ecd5f3ea3e172312d52e7da586dcd5f7ce8770d198b298618073b122-image.png)
