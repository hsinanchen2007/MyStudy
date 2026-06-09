### 解题思路
1. `一般的与二进制有关的都需要位运算来完成`
2. `设置一个累加器res，判断n&1的值分为两种情况`
    - 当 n & 1 == 1时，说明二进制的最右位为1
    - 当 n & 1 == 0时，说明二进制的最右位为0
3. `当 n & 1 == 0时，说明二进制的最右位为0,则将无符号数向右移位一位` 
### 代码

```python
class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        res = 0
        while n:
            res += n & 1
            n >>= 1
        return res
```