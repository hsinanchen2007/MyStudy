### 解题思路
- 两数先进行异或
- 结果转换为二进制数，切片去除0x
- 去除二进制数中所有的零，计算字符串长度

### 代码

```python
class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        return len(bin(x^y)[2:].replace('0',''))
```