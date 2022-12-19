### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def divisorGame(self, N: int) -> bool:
        if N == 1:
            return False
        elif N == 2:
            return True

        dp = [None] + [None for i in range(N)]

        dp[1], dp[2] = [False, True]

        for nth in range(1, N + 1):
            # 递推，获取局部最优解，第n个数谁会赢，n+1由n得出
            for num in range(1, nth // + 1):
                """
                首先1肯定输，直接动不了
                
                2，拿一个变为1，拿一个后结果为False,2能赢
                
                第三个，找一个大于1小于n的数(1<num<n),且能被n整除的数，枚举所有，如果减去之后dp[n - num]为False,那么就能赢
                
                
                dp[n]就设置为True
                否者设置为False
                
                """
                if nth % num == 0 and dp[nth - num] == False:
                    dp[nth] = True
                    break
            else:
                dp[nth] = False
        return dp[-1]
```