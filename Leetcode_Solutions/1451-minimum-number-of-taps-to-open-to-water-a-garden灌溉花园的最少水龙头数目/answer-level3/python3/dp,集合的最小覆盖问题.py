### 解题思路
先处理集合，得到最大范围的(r, l)的元组list。
dp序列初始化，每个值都定为最大值，然后dp迭代。
对于每个(r, l)，如果l=0，则dp[r]=1,否则，
dp[r] = min([dp[i]] for i in range(l-1, r)]) + 1，
搞定。

### 代码

```python3
class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        g = {}
        for i in range(n+1):
            if ranges[i] == 0:
                continue
            l = i - ranges[i]
            r = i + ranges[i]
            if l < 0:
                l = 0
            if r > n:
                r = n
            if r not in g.keys():
                g[r] = l
            else:
                if l < g[r]:
                    g[r] = l        
        g = [(k, v) for k, v in g.items()]
        g = sorted(g)
        # print(g)
        dp = [1e4]*(n+1)
        for r, l in g:
            if l == 0:
                dp[r] = 1
            else :
                tmp = dp[l:r]
                dp[r] = min(tmp)+1
        if dp[n]<1e4:
            return dp[n]
        else:
            return -1
```