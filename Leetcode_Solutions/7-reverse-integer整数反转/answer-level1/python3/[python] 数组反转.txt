1. 把整数转成字符串
2. 判断首位是否是 ‘-‘，若是参数neg=-1,将数组中的’-’去掉; 若否neg=1
3. 数组反转
4. 转化为整数类型，结果 × neg
4. 判断数组范围是否在上下线内，若是则放回res,若否放回0



```
class Solution:
    def reverse(self, x: int) -> int:
        str_x = str(x)
        str_x_list = [i for i in str_x]
        neg = 1
        if str_x_list[0] == '-':
            neg = -1
            str_x_list = str_x_list[1:]
        str_x_list.reverse()
        res = ''.join(str_x_list)
        res = neg * int(res)
        up = math.pow(2, 31) - 1
        down = -math.pow(2, 31)
        if res > up or res < down:
            return 0
        return res
```
