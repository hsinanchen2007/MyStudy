```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0]=nums[0];
        int res=dp[0];
        for(int i=1;i<nums.size();i++){
            dp[i]=max(dp[i-1],0)+nums[i];
            res=max(dp[i],res);
        }
        return res;

    }
};
```

我对动态规划的理解是它由俩个部分组成：

* dp数组
* 状态转移方程（递推公式）

我们首先要建立一个dp数组，它能够表达一定的含义，其中代表的含义也可以分为以下几类：

* 主语：通常是一个集合、是一类数，这里是以i为结尾的字段
* 形容词：例如：最大值、最小值、和，这里代表和的最大值

两者结合起来`dp[i]`的含义就是以i结尾的字段的和的最大值。

根据这个含义可以写出状态转移公式：

`dp[i]`的值等于`dp[i-1]`和0的最大值加上`nums[i]`，因为如果`dp[i]`最大且`dp[i-1]`大于0，则`dp[i-1]`也最大，如果`d[i-1]`小于0，那么前面的数就不用加上去了，因为加起来必然比`nums[i]`要小，所以不如只取`nums[i]`，所以递推公式为：
$$
dp[i]=max(dp[i-1],0)+nums[i]
$$
然而提交上去，显示内存占用仅超过了$9.36\%$的用户，这怎么能忍，于是我们用滚动数组来优化内存：

由于`dp[i]`的值只和前一个数有关系，我们可以用滚动数组来优化，即dp数组的长度为2就可以了，这样我们就可以写出这样的递推公式:
$$
dp[i\&1]=max(dp[i-1\&1],0)+nums[i]
$$
这里位运算$\&1$的作用实际上就是求对2的余数，这样可以把当前状态和前一个状态区分开来了。

稍作修改可以得到如下的程序：

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(2);
        dp[0]=nums[0];
        int res=dp[0];
        for(int i=1;i<nums.size();i++){
            dp[i&1]=max(dp[i-1&1],0)+nums[i];
            res=max(dp[i&1],res);
        }
        return res;

    }
};
```
