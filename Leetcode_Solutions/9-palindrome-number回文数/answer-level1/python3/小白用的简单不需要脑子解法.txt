### 解题思路
这道题一直条件成立只能是大于0的，故先用if判断排除小于0的。其次将该数字用内置str函数转化为字符串，然后就可以将该数字的逆序打出，然后再将他转化为整数型，运用if语句即可。

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        elif x > -1 :
            str_x = str(x)
            str_x = str_x[::-1]
            y = int(str_x)
            if y == x:
                return True
            else:
                return False
```