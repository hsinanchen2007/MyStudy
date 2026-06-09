```
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        # 获取 x 正负符号方法：
        # sign = 1 if x >0 else -1,
        # sign = [1, -1][x < 0],
        # sign = cmp(x, 0).

        # # 1
        # old_str = str(x)
        # new_str = ''
        # for i in range(len(old_str)):
        #     new_str = new_str + old_str[len(old_str) - 1 - i]
        # if x < 0:
        #     new_str = new_str[-1] + new_str[:-1]
        # if int(new_str) < -(2**31) or int(new_str) > 2**31 - 1:
        #     return 0
        # else:
        #     return int(new_str)
        
        # 2
        sign = [1, -1][x < 0]
        y = sign * int(str(abs(x))[::-1])
        if y < -(2**31) or y > 2**31 - 1:
            return 0
        return y
```
