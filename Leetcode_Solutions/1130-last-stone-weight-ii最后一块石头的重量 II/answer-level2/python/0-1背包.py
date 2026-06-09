### 解题思路
看题解
比如有四个石头, a b c d
第一次挑出来a,b 得到新石头a-b, 第二次挑出来c, 得到新石头c-a+b. 
所以可以看到最后一块石头是所有石头加减的结果
所以可以转化为分成两堆石头 求最小差值的问题
也就是求一堆石头最接近sum/2的问题
所以为0-1背包, dp[i][j]代表选i个石头的最大重量j, 其中容量为sum/2, 即求最大的j<sum/2


### 代码
```python3
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        total, l = sum(stones), len(stones)
        dp = [[0]*(total//2+1) for _ in range(l+1)]
        for i in range(1, l+1):
            for j in range(1, total//2+1):
                if stones[i-1]<=j: # 这个代表选第i个, 然后再去比较选之后的大小
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-stones[i-1]]+stones[i-1])
                else: dp[i][j] = dp[i-1][j] # 这个代表不选第i个
        return total-2*dp[-1][-1]
```


```
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        total, l = sum(stones), len(stones)
        dp = [0]*(total//2+1)
        for i in range(0, l): # 因为没有了i-1所以可以从0开始
            for j in range(total//2, stones[i]-1, -1):
                    dp[j] = max(dp[j], dp[j-stones[i]]+stones[i])
        return total-2*dp[-1]
```