### 解题思路
方法一
动态规划，可当作完全背包问题，dp = [i for i in range(n+1)]
转移公式为dp[i] = min(dp[i],dp[i-j]+1)
方法二
广度优先搜索
![image.png](https://pic.leetcode-cn.com/911a9624ebc445fe4a1949caddeb75c1486fc96cdbf8a89ec5e6e1da437b78b1-image.png)

### 代码

```python3
class Solution:
    def numSquares(self, n: int) -> int:
        #动态规划&完全背包
        tmp = []
        for k in range(1,n):
            if k*k <= n:
                tmp.append(k*k)
            else:
                break
        dp = [0]*(n+1)
        for i in range(1,n+1):
            dp[i] = i
            for j in tmp:
                if i >=j:
                        dp[i] = min(dp[i],dp[i-j]+1)
        return dp[n]
        #广度优先搜索
        from collections import deque
        tmp = []
        for k in range(1, n):
            if k * k <= n:
                tmp.append(k * k)
            else:
                break
        if n == 1:
            tmp.append(1)
        queue = deque([n])
        queue.appendleft(0)
        visted = set()
        while queue:
            num = queue.pop()
            d = queue.pop()
            d = d + 1
            for no in tmp:
                if (num - no) == 0:
                    return d
                elif (num-no) in visted:
                    continue
                else:
                    queue.appendleft(num - no)
                    queue.appendleft(d)
                    visted.add(num-no)
```