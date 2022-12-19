### 解题思路
深度优先遍历
def dfs(cur_str, left, right)
    if left == 0 and right == 0:
    if right < left:
    if left > 0:
    if right > 0:


### 代码

```python
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """

        res = []
        cur_str = ''

        def dfs(cur_str, left, right):
            if left == 0 and right == 0:
                res.append(cur_str)
                return
            if right < left:
                return
            if left > 0:
                dfs(cur_str+'(', left-1, right)
            if right > 0:
                dfs(cur_str+')', left, right-1)


        dfs(cur_str, n, n)
        return res


```