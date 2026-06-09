### 解题思路
继续笨办法，拿到数字先判是否为负数，立flag，之后列表化反取，拼接重新整数化，再根据flag判断是否为负数，最后做数字校验，完成。
### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        flag = False
        if x < 0:
            flag = True
        ls = list(str(abs(x)))
        a = ls[::-1]
        a = "".join(a)
        a = int(a)
        if flag:
            a = 0 - a
        else:
            pass
        if -2147483648 <= a <= 2147483647:
            pass
        else:
            return 0
        return a

```