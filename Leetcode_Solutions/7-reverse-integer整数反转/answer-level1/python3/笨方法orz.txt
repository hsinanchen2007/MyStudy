### 解题思路
先把int转换成str，将str倒序，再把字符串转换成int，用时太长

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        def dict(s):
            dict = {'1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9':9, '0':0}
            return dict[s]
        
        def digit(s):
            num = 0
            for i in s:
                num = 10 * num + dict(i)
            return num
        x_str = str(x)
        if x >= 0:
            result = digit(x_str[::-1])
        else:
            x_str1 = x_str[1:]
            result = -digit(x_str1[::-1])
        if result > 2**31 - 1:
            return 0
        elif result >= -2**31:
            return result
        else:
            return 0
    

                
        
            

```