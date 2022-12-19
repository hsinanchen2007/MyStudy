TLE解法：
求每个硬币的最小使用次数
coinchange(x,coins,S):x为硬币在列表中的下标，S为使用了i个面值为coins[x]后的值。
主要思路，假设已经用掉i个面值为coins[x]的硬币，求剩下的费用需要的最小硬币。

def coinchange(x:int, coins:list, S:int) -> int:
    if S==0: return 0    
    if x<len(coins) and S>0:
        cnt = int(S/coins[x])
        min_temp = int(S/coins[0]) + 1
        for i in range(cnt+1):
            if i*coins[x] <= S:
                res = coinchange(x+1, coins, S-i*coins[x])
                if res != -1:
                    min_temp = min(min_temp, res+i)
        if min_temp != int(S/coins[0]) + 1:
            return min_temp
    return -1
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        return coinchange(0, coins, amount)
