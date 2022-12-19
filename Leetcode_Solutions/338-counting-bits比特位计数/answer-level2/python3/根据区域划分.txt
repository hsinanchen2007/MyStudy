```
class Solution:
    def countBits(self, num: int) -> List[int]:
        dp = [0]
        _pow = 0
        for _ in range(1, num+1):
            if _ < pow(2, _pow+1):
                pass
            else:
                _pow = _pow + 1
            offset = _ - int(pow(2, _pow))
            dp.append(dp[offset]+1)
        return dp
```
