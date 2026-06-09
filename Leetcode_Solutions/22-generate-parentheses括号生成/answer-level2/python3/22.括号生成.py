### 解题思路
看了官方题解又，
真是，唉，思想是个好东西
可惜我没有啊。

看了思想后重写代码时，注意加右括号的前提是左括号多于右括号。

回溯算法真是好用，这么看起来的话。

执行用时：16ms      击败96.52%
内存消耗：12MB      击败26.54%

### 代码

```python
class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        def backTrack(S,left,right):
            if len(S) == 2*n:
                res.append(S)
                return
            # 只要左边的括号不够，直接添加
            if left < n:
                backTrack(S+'(',left+1,right)
            # 添加右边括号的前提是左边括号多了一个才能加
            if right < left:
                backTrack(S+')',left,right+1)
        
        backTrack('',0,0)
        return res


```