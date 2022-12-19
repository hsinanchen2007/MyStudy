### 解题思路

深度优先遍历，但是需要保证所有时刻右括号的数目要大于等于左括号的数目

同时能够生成的合法的括号的数目也是卡特兰数$\frac{C_{2n}^{n}}{n+1}$。


### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
    
        def dfs(res, n, m):
            if n == 0 and m == 0:
                r.append(res)
                return
            if n > 0:
                res += "("
                n -= 1
                dfs(res, n, m)
                res = res[:-1]
                n += 1
            if n < m:
                res += ")"
                m -= 1
                dfs(res, n, m)
                m += 1
                res = res[:-1]
        
        res = ""
        r = []
        dfs(res, n, n)
        return r
```