![image.png](https://pic.leetcode-cn.com/07494c5e0565429899b94b988154e783b9554258b8cdfdf7236e3f840f5fceca-image.png)



```

'''
动态规划
dp(i, j) 表示总共i首歌，恰好出现j种歌曲的方法数
最终答案是dp(L, N)

看歌曲序列最后一首歌，如果最后一首歌是前面i-1首歌中都没出现的
那方法数有 dp(i-1, j-1) * (N - (j-1)) 种

如果最后一首歌是前面i-1首歌中已经出现过的， 根最后一首歌距离小于等于k的前面k首歌
肯定都是不一样的，最后一首歌不能和这k首歌一样，最后一首歌可以有j-k中选择
方法数有 dp(i-1, j) * (j-k) 种

两种情况需要加起来


'''

class Solution:
    def numMusicPlaylists(self, N: int, L: int, K: int) -> int:
        MOD = 1000000007
        dp = [[0 for i in range(N+1)] for j in range(L+1)]
        dp[0][0] = 1
        for i in range(1, L+1):
            for j in range(1, N+1):
                dp[i][j] = (dp[i-1][j-1] * (N - (j-1)) + dp[i-1][j] * max(0, j-K)) % MOD
        return dp[L][N]

```


