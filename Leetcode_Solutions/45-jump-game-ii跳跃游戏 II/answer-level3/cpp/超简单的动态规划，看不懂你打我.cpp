
```c++ []
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        vector<int> start(nums.size(), 0);
        if(nums.size() <= 1)return 0;
        dp[1] = 1;
        start[1] = 1;
        for(int i = 2; i < nums.size(); i++)
        {
            dp[i] = dp[i-1]+1;
            start[dp[i]] = i;
            for(int j = start[dp[i-1]-1]; j < start[dp[i-1]]; j++)
            {
                if(j + nums[j] >= i)
                {
                    dp[i] = dp[i-1];
                    break;
                }
            }
        }
        return dp[nums.size()-1];
    }
};
```
对于这一题  有这样一个性质，若到i最少需要n步跳跃，则跳到i前面的点一定会小于等于n步。
![image.png](https://pic.leetcode-cn.com/ff1c4df9ecbbf39da9c3c55b1725e08d553a172e8576347fba9561328510779e-image.png)

图中start代表的是各个dp值的起始位置，如dp值为0的索引为0，dp值为3的起始索引为5；
而**dp代表的是跳跃到该点的最小步数**。

![image.png](https://pic.leetcode-cn.com/99a0eb886f03b6e15e99d902ed92e2d2cee52e32312e36a77d164cf0c4b6a7cb-image.png)

如图  此时想确定dp[5]的值，根据dp[4]=2;则dp[5]一定等于dp[4]或者dp[4]+1;
使得dp[5]等于dp[4]的条件是什么呢？
由于dp[4]已经等于2了，所以我们需要去dp值等于1的地方查找，即在start[1]~start[2]范围内查找，看是否有dp值等于1的点可以到达dp[5];若存在则dp[5]等于dp[4],不存在，则dp[5]等于dp[4]+1，且插入新的start值有效。


这超级详细了吧。  客官，点个赞呗！