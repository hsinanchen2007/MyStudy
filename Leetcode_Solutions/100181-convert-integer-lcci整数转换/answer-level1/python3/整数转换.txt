### 解题思路
先去记录两个数位置上的不同（即做与运算），然后计算得到数有多少个1，但注意异或运算的结果和 0xffffffff 进行与运算，忽略符号位 （这句目前没太懂）

### 代码

```python
class Solution(object):
    def convertInteger(self, a, b):
        """
        :type A: int
        :type B: int
        :rtype: int
        """
        count = 0
        c = (a ^ b) & 0xffffffff
        while (c != 0):
            c = c & (c - 1)
            count += 1
        return count

```