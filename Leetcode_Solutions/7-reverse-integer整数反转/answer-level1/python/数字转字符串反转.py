### 解题思路
数字先转字符串进行反转，反转时有正负区分，不要取负号，反转后转换为数字，进行范围判断，进行返回

### 代码

```python
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x < 0:
            x = int("-" + str(x)[: 0:-1])
        else:
            x = int(str(x)[::-1])
        if pow(2, 31) - 1 < x or x < pow(-2, 31):
            return 0
        return x
```