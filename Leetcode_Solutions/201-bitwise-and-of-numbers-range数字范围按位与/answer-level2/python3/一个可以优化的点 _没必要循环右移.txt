思路都是最后几位不用考虑,有0出现就必定是0.

有一个优化的点就是到底是几位必定为0.

现在大多数是循环向右移位.
其实就是数学题,没必要循环,直接求差,差值的二进制位数就是该移动的位数.

    class Solution:
    def rangeBitwiseAnd(self, m: int, n: int) -> int:      
        k = n-m
        if k != 0:
            temp = k.bit_length()
            m>>=temp
            n>>=temp
            res = m&n
            res <<= temp
            return res
        else :
            return m


时间为60ms
![image.png](https://pic.leetcode-cn.com/505e32860591ccd542dcd59bb9b912bd8bb26354849739dc01df8eac6b14267d-image.png)
