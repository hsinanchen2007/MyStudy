### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        # 用字典表示可能的组合
        d = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        d2 = {'IV':4, 'IX':9, 'XL':40, 'XC':90, 'CD':400, 'CM':900}
        res = 0
        len_s = len(s)
        is_end = True

        # 要么两位,要么一位
        # 从右往左,向前多看一位
        i = len_s - 1
        while i >= 0:
            if i > 0 and (s[i-1:i+1] in d2): # 两位
                res += d2[s[i-1:i+1]]
                i -= 2
            else:                            # 一位
                res += d[s[i]]
                i -= 1
        return res
```