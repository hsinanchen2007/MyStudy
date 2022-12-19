与二进制位全是1的数进行异或操作即为所得结果
```python
class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        length = len(bin(num))-2 #二进制位数的长度
        n = (1 << length) - 1    #将1左移length位，并减1得到二进制数位全是1的长度位length的数
        return n ^ num #异或
```
