1. bin(num).count('1')
执行用时 :80 ms, 在所有 Python 提交中击败了60.63%的用户

```
class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        L = [0]
        for i in range(1, num + 1):
            L.append(bin(i).count('1'))
        return L
```


2. 根据 191. Number of 1 Bits 启发
执行用时 : 220 ms, 在所有 Python 提交中击败了6.62%的用户
内存消耗 : 13.8 MB, 在所有 Python 提交中击败了98.74%的用户

```
class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        """
        1: 001
        2: 010

        001 + 001
        - xor异或 + and操作 后 左移动运算符 << 1
        """
        L, xor, carry = [0], 0, 1
        while(xor < num):
          # 异或, 进位
          xor, carry = xor ^ carry, (xor & carry) << 1
          print xor, carry
          if (carry != 0): 
              xor += carry

          carry = 1
          L.append(bin(xor).count('1'))
        return L

```
