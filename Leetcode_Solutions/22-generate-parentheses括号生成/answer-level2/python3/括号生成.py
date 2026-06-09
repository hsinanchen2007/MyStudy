### 解题思路
回溯算法：1.可直接暴力; 2.剪枝:引入a,b分别对应'('和')'的个数, 当a>n//2 返回,当b>a返回.

### 代码

```python
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []

        def backtrack(path, n, a, b):
            if len(path) == n and isValid(path) == 0:
                result.append(''.join(path))
                return
            if len(path) < n:
                if a > n//2:
                    return
                path.append('(')
                backtrack(path, n, a+1, b)
                path.pop()
                if b > a:
                    return
                path.append(')')
                backtrack(path, n, a, b+1)
                path.pop()

        def isValid(path):
            k = 0
            for x in path:
                if k < 0:
                    return -1
                if x == '(':
                    k += 1
                else:
                    k -= 1
            return k
        backtrack([], 2*n, 0, 0)
        return result
```