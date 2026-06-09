### 解题思路
先将二进制转换成十进制相加，之后转成二进制输出
从第三个元素输出，前两个元素为'0b'二进制标志
时间击败90%
内存消耗有点多
### 代码

```python
class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        a=int(a,2)
        b=int(b,2)
        return bin(a+b)[2:]#二进制前两位为0b二进制标志
```