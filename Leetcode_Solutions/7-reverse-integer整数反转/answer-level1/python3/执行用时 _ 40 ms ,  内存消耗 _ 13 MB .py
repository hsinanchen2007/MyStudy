### 解题思路
1. 先直接将x字符串化再倒序放进列表；
2. 判断是否以‘-’结尾，是就去掉再把结果组成字符串再转成int并乘-1；
3. 否则直接转成int；
4. 判断x有没有超出范围，有则=0，没有则返回；
（注意：int()可以直接将开头为‘0’的字符串忽略，返回一个非零开头的整数，如：int(‘00123’)== 123 ）
### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:       
        x = list(str(x))[::-1]
        if x[-1] == '-':
            x[:] = x[:len(x)-1]
            x = -1 * int(''.join(x))   
        else:
            x = int(''.join(x))    
        if x not in range(-2**31 , 2**31 - 1):
            x = 0
        return x
```