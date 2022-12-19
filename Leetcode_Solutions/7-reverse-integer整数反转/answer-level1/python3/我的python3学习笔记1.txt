### 解题思路
此处撰写解题思路
很简单的回文数题目，但是要注意一些地方：
1 返回的整数要在区间内
2 负数如何处理
3 对十进制的概念要熟悉
4 python的各种运算符号，幂，逻辑运算符等等
### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        negative =0
        if x<0:
            negative = 1
            x = abs(x)
        
        
        l = len(str(x))-1
        y = 0
        number = 0
        
        

        while x>=10:
            y = x%10
            x = x//10
            number = number + y*(10**l)
            l = l-1
        
        number = number+x
        if number > (2**31-1) or number<(-2**31):
            number = 0
        if negative == 1:
            return (0-number)
        else:
            return number

        
```