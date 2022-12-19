### 思路

我们用一个数组 dp 来表示“在只剩下第 i 堆到最后一堆石子时，当前玩家最多能拿多少分”。假如算出了这个 dp 数组，那么最终答案就是判断 dp[0] 和（分数总和-dp[0]）之间的大小关系即可。

我们倒着计算这个 dp 数组。首先计算边界情况：dp[n-1] = s[n-1]，因为最后一个堆的时候只能拿走。

对于其他的 i，我们可以这样思考：当前你的选择有 “取走一、二、三堆”，结果就是给对方留下了 dp[i+1] dp[i+2] dp[i+3] 对应的情况。也就是对方能够得到的最高分就是 dp[i+1] dp[i+2] dp[i+3] 中的一个，而我们能得到的分数就是剩下的所有分数减去对方能拿到的分数。为了让我们拿到的更多，就得让对方拿到的最少。

因此有 dp[i]= sum{i,n} - min{dp[i+1],dp[i+2],dp[i+3]}，分别对应取走一堆、两堆、三堆石子的情况。

通过 dp[n-1] 和 递推式，利用动态规划我们就能算出 dp[0]，从而得到答案了。

博弈论题第一次见肯定懵逼。本题属于信息透明的平等博弈，是博弈论中最基础的一种，思路就是倒着从游戏的最后一步开始反着算，对每个状态计算“玩家从该状态开始能不能获胜/最多能拿多少分”，用类似动态规划的思想一直算到第一步。

对博弈论方面有兴趣的同学，推荐cxlove 大佬的两篇博客：

博弈类入门：<https://blog.csdn.net/acm_cxlove/article/details/7854530>

博弈类进阶：<https://blog.csdn.net/acm_cxlove/article/details/7854526>



### 代码

比赛时写的，比较丑见谅。变量名 su 表示 sum，cho 表示 choose。

```
class Solution:
    def stoneGameIII(self, s: List[int]) -> str:
        su = 0
        dp = [0]*(len(s)+1)+[10000000]*4
        for i in range(len(s)-1, -1, -1):
            su += s[i]
            cho = min(dp[i+1],dp[i+2],dp[i+3])
            dp[i] = su - cho
   #    print(dp)
        if dp[0]+dp[0]<su:
            return "Bob"
        elif dp[0]+dp[0]>su:
            return "Alice"
        return "Tie"
```

