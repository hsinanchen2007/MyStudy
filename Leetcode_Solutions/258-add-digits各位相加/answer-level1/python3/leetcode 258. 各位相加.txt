存在集中情况：
当数字为0-9时，结果为它本身，
当数字大于9，且为9的倍数时，结果为9，
当数字大于9，且不为9的倍数时，结果为该数mod 9 的余数
代码如下：
```
class Solution:
    def addDigits(self, num: int) -> int:
        if num<9:
            return num
        elif num%9:
            return num%9
        else:
            return 9
```