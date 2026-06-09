### 解题思路
首先判断的符号然后利用字符串进行倒置

### 代码

```python
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        flag = 1
        if x < 0:
            flag = -1
            x = -x
        y = int(str(x)[::-1])
        if y*flag >=-2**31 and y*flag <= 2**31-1:
            return (y*flag)
        else:
            return 0


```