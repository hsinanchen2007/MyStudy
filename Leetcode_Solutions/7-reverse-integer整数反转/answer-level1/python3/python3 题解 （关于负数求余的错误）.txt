python3 题解 （关于python3 负数求余的错误）
在异号的整数运算中，C++和Java会让商尽可能大（比如-7/3中，d=-2,r=-1）。
Python等则让商尽可能小（比如-7/3中，d=-3，r=2）。
代码如下：
class Solution:
    def reverse(self, x: int) -> int:
        rev_value = 0
        max_value = 2 ** 31 -1
        min_value = -(2 **31 )
        if x<0:
            flag = -1
            x = -x
        else:
            flag = 1
        while x != 0:
            pop = x%10
            x = x//10
            rev_value = rev_value * 10 + pop
            if (rev_value>max_value and flag == 1) or (rev_value > max_value+1 and flag ==-1):
                return 0
        return rev_value*flag