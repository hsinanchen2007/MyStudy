### 解题思路
从左往右一位一位的看:
- 如果这一位数字比它右边一位的数字大或与其相等，则加上这一位代表的值
- 如果它比右边一位小，则减去这一位代表的数字。

### 代码

```python3
class Solution:
    def __init__(self):
        self.dic = {'I':1, 'IV':3, 'V':5, 'IX':8, 'X':10, 'XL':30, 'L':50, 'XC':80, 'C':100, 'CD':300, 'D':500, 'CM':800, 'M':1000}

    def romanToInt(self, s: str) -> int:
        res = 0
        for i in range(len(s)):
            if i < len(s)-1 and self.dic[s[i]] < self.dic[s[i+1]]:
                res -= self.dic[s[i]]
            else:
                res += self.dic[s[i]]
        return res

        
```