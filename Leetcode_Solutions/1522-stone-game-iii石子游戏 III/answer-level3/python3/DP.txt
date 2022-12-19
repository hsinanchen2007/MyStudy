### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        dp = [-1e9]*len(stoneValue)
        dp[-1] = stoneValue[-1]
        dp += [0]*2
        summ = stoneValue[-1]
        for i in range(len(stoneValue)-2,-1,-1):
            summ += stoneValue[i]
            dp[i] = summ-min(dp[i+1],dp[i+2],dp[i+3])
        alice = dp[0]
        bob = summ-dp[0]
        if alice==bob:return 'Tie'
        elif alice>bob:return 'Alice'
        else:return 'Bob'
```