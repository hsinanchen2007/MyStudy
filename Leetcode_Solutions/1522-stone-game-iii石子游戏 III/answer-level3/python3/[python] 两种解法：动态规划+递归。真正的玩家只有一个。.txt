解法1：动态规划。从后往前，关键是理解两人角色的互相转换，其实在任何一个位置，玩家只有一个，就是想要最大化当前收益的玩家。击败100%
```
class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        dpscore = [None] * (len(stoneValue)+1)
        dpscore[-1] = 0
        dpscore[-2] = stoneValue[-1]
        for i in range(len(dpscore) - 2, -1, -1):
            v = stoneValue[i] - dpscore[i+1]
            if(i + 2 <= len(dpscore) - 1):
                v = max(v, stoneValue[i] + stoneValue[i+1] - dpscore[i+2])
            if(i + 3 <= len(dpscore) - 1):
                v = max(v, stoneValue[i] + stoneValue[i+1] + stoneValue[i+2] - dpscore[i+3])
            dpscore[i] = v

        if(dpscore[0] > 0): return "Alice"
        elif(dpscore[0] < 0): return "Bob"
        else: return "Tie"
```


解法2：带记忆的递归。关键也是理解两人角色的互相转换。击败100%
```
class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        score = [None] * len(stoneValue)
        start = 0
        
        def game(stonevalues, start):
            values = stonevalues
            if(start >= len(values)):
                return 0
            if(score[start] != None): return score[start]
            if(start <= len(values) - 1):
                v = values[start] - game(values, start+1)
            if(start + 1 <= len(values) - 1):
                v = max(v, values[start] + values[start+1] - game(values, start+2))
            if(start + 2 <= len(values) - 1):
                v = max(v, values[start] + values[start+1] + values[start+2] - game(values, start+3))
            score[start] = v
            return v
            
        res = game(stoneValue, 0)
        if(res > 0): return "Alice"
        elif(res < 0): return "Bob"
        else: return "Tie"
```