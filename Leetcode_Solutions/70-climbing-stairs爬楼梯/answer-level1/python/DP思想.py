### 解题思路
根本是大问题与小问题之间的转化。<br />
n阶台阶，两种跳法<br />
第一次如果跳1阶，就还有n-1阶；
第一次如果跳2阶，就还有n-2阶<br />
设 跳法有 f(x) 种 <br />
所以n阶台阶就一共有 f(n - 1) + f(n -2) 种。
### 代码

```python
class Solution(object):
    
    def __init__(self):
        self.dp = {}

    def solution(self, n):
        if n == 1:
            return 1
        elif n == 2:
            return 2
        if self.dp.get(n, 0):
            return self.dp[n]
        else:
            res = self.climbStairs(n - 1) + self.climbStairs(n - 2)
            self.dp[n] = res
            return res

    def climbStairs(self, n):
        d = {}
        print(d.get(9, 0))
        return self.solution(n)
```