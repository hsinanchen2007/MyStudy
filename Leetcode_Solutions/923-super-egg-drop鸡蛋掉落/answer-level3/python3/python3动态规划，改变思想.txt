*参考https://leetcode-cn.com/problems/super-egg-drop/solution/ji-ben-dong-tai-gui-hua-jie-fa-by-labuladong/。*

**最重要的是变换思想，从知道鸡蛋数K，知道层数N，求最少次数M；转化为知道鸡蛋数K，假设最多只能扔M次，求最大能排除的层数。**

创建一个二维列表dp[K][N]来记录最大能排除层数（M<=N，即使一层一层扔，最多也只会扔N次，保证不会溢出）。
```python3
dp[:][:]
```

0个鸡蛋，无论扔多少次，只能排除0层数；无论多少鸡蛋，扔0次，只能排除0层数。

```python3
dp[0][:]=0，dp[:][0]=0
```

某一状态，总共有k个鸡蛋，最多扔m次，要找的那一层为第F层。因为dp记录的是最大能排除的层数，所以我们扔的这一层，是最佳的。也就是，能排除F在楼上的情况：蛋没碎，那么还有k个鸡蛋，可以扔m-1次；能排除F在楼下的情况：蛋碎了，那么还有k-1个鸡蛋，可以扔m-1次；能排除F就在当前楼。
```python3
dp[k][m] = dp[k][m-1]+dp[k-1][m-1]+1
```

知道了上面的转移方程，我们可以用两个循环，外循环是m一次一次增加，内循环是k一个一个增加。当某一循环中，扔K个鸡蛋可以排除超过N层了，那么说明，当前的m次就足够了。

```python3
for m in range(1,N+1):
   for n in range(1,K+1):
       dp[k][m] = dp[k][m-1]+dp[k-1][m-1]+1
   if dp[K][m] >= N:
       return m
```

仔细观察，会发现，这个状态转移方程可以简化成如下的一维列表。

```python3
class Solution:
    def superEggDrop(self, K: int, N: int) -> int:
        if K == 1 or N == 1:
            return N
        dp = [0 for _ in range(K+1)]
        ans = 0
        while dp[K] < N:
            for k in range(K, 0, -1):
                dp[k] = dp[k]+dp[k-1]+1
            ans += 1
        return ans
```

想明白还是很费脑子的，可以在纸上画个表格，手动进行状态转移，加深理解。