### 解题思路
主要记录下0ms且两个都是100%（emmm...就乐了一秒，发现大家都是0ms，看来是数据太小了）
典型的动态规划题目。
到达第n格的方法有：①从第n-2格跨两步；②从第n-1格跨一步。那么到达第n格的方法就有dp[n-1]+dp[n-2]种。

贴个图开心一下o(*￣▽￣*)ブ
![批注 2020-04-05 212453.jpg](https://pic.leetcode-cn.com/0a52572300a946b0a58ee5a8537c85c99ba607dab30c4dda29c5736890860e5c-%E6%89%B9%E6%B3%A8%202020-04-05%20212453.jpg)



### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++) dp[i]=dp[i-1]+dp[i-2];
        return dp[n];
    }
};
```