### 解题思路
因为本题中括号只有一种，我们可以发现，在任何位置，左括号的数量一定大于等于右括号，也就是说，在左括号数量小于n时，我们可以添加左括号，并且在当前右括号数量小于左括号数量时，我们可以添加右括号。当序列长度等于2n时停止并返回结果。

### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        def backtrack(S='', left=0, right=0):
            if len(S)==n*2:
                ans.append(S)
                return
            if left<n:
                backtrack(S+'(', left+1, right)
            if right<left:
                backtrack(S+')', left, right+1)
        backtrack()
        return ans
```