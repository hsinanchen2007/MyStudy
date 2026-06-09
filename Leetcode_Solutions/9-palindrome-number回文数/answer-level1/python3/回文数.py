### 解题思路
执行太慢

### 代码

```python3
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if str(x)[0] == '-':
            return False
        else:
            temp = ''
            for i in range(len(str(x))):
                temp += str(x)[len(str(x))-i-1]
            if temp == str(x):
                return True
            else:
                return False
```
执行用时 : 124 ms
内存消耗 : 13.3 MB

别人的解法
class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        else:
            y = str(x)[::-1]
            if y == str(x):
                return True
            else: 
                return False

字符串切片
其中str(x)[::-1]：-1表示从后往前读取字符串  ':'表示字符串的全部
str(x)[n::-1]：-1表示从第n个字符开始，往前读取字符串