### 解题思路
A*B 等于B个A相加

### 代码

```python
class Solution(object):
    def multiply(self, A, B):
        """
        :type A: int
        :type B: int
        :rtype: int
        """
        if B==0:
            return 0
        if B==1:
            return A
        return A + self.multiply(A, B-1)
```