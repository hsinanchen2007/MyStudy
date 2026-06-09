### 解题思路
递归

### 代码

```python
class Solution(object):
    def sumNums(self, n):
        """
        :type n: int
        :rtype: int
        """
        def sumN(n):
            return n and sumN(n-1)+n
        return sumN(n)

```