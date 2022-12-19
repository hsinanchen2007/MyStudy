#深搜，因为变量是两个：目前可用左括号个数left和目前可用右括号个数right
```
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        self.dfs('', n, n, res)
        return res
    def dfs(self, temp, left, right, res):
        if left == right == 0:
            res.append(temp)
            return 
        if left > right:
            return 
        if left:
            self.dfs(temp + '(', left - 1, right, res)
        if right:
            self.dfs(temp + ')', left, right - 1, res)
```