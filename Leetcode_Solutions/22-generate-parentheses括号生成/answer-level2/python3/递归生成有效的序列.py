### 解题思路
设定左括号个数，右括号个数来控制有效性
递归生成长度为2*n的序列

和dfs的思想其实是一样的
### 代码

```python3
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        def backtrack(S,left,right):
            if len(S) == 2*n:
                ans.append(S)
                return 
            if left < n:
                S = "".join([S,"("])
                backtrack(S,left+1,right)
                S = S[:-1]
            
            if left > right:
                S = "".join([S,")"])
                backtrack(S,left,right+1)
            
        backtrack("", 0, 0)
        return ans
            
```