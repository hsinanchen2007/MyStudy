**解题思路：**
利用map
**代码：**
```
class Solution(object):
    def sortedSquares(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        def f(x):
            return x*x
        B = map(f,A)
        B.sort()
        return B
```
