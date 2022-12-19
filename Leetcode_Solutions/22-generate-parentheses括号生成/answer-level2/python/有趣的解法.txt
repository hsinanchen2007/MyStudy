### 解题思路
二叉树的理念，用代码实现dfs，人并不需要理解，足矣

### 代码

```python
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        if n == 1: return ['()']
        if n < 1: return []
        rl = []
        #有l个左括号、r个右括号、当前字符串为s
        def tree(s='', l=0, r=0):
            if l < n:
                tree(s+'(',l+1,r)
            if r < l:
                tree(s+')',l,r+1)
            if len(s) == n*2:
                rl.append(s)
        tree()
        return rl
```