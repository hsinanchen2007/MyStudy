### 解题思路
这里用的整数翻转实现，当然转换为字符串然后切片更简单

### 代码

```python
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        index = 0
        if x < 0:
            x = - x
            index = 1
        y = 0
        while x > 0:
            y = 10 * y + x%10
            x = x/10
        if index == 0 and y < 2147483647:
            return y
        elif index == 1 and y < 2147483647:
            return -y
        else:
            return 0
```