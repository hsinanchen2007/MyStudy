```
class Solution:
    def twoSum(self, n: int) -> List[float]:
        dp = [0] * (1+6*n)
        for i in range(1,7): dp[i]=1
        for i in range(2,n+1):
            for j in range(6*i, i-1,-1):
                dp[j]=0  #?????需要清空上一轮的值
                for k in range(1,7):
                    if j -k < i-1:#????上一轮掷骰子的最小值
                        break
                    dp[j] += dp[j-k]
        
        res = dp[n:]
        s = sum(res) #?????? sum(res) == 6**n
        ans = [ i/s for i in res]
        return ans
```
