### 解题思路
1、先将字符串转换成小写（注意lower()函数需要用一个新的变量接收，不能修改原字符串）；
2、去除非字母和数字；
3、输出反转的新字符串；
4、比较去杂的字符串和反转后的字符串，相同则为True，否则为False。

### 代码

```python3
class Solution:
    def isPalindrome(self, s: str) -> bool:
        if s is None:
            return True
        lower_s = s.lower()
        new_s = ""
        for char in lower_s:
            if char.islower():
                new_s += char
            if char.isdigit():
                new_s += char
        new_s_reverse = ""
        for i in range(len(new_s), 0, -1):
            new_s_reverse += new_s[i-1]
        if new_s == new_s_reverse:
            return True
        else:
            return False
```