### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        self.ans = []

        def dfs(n, arr, s):
            ln = len(arr)
            if n == 0 and ln == 0:
                self.ans.append(s)
                return
            elif n == 0 and ln != 0:
                arr.pop()
                dfs(n, arr, s + ')')
            elif n != 0 and ln == 0:
                arr.append('(')
                dfs(n - 1, arr, s + '(')
            else:
                tmp1 = arr[:]
                tmp1.append('(')
                dfs(n - 1, tmp1, s + '(')
                arr.pop()
                dfs(n, arr, s + ')')

        dfs(n, [], '')
        return self.ans
            
```