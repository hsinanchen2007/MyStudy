### 解题思路
此处撰写解题思路
找规律，前个字母一般比后个字符大。前个字母不小于后一个则加，否则减


### 代码

```python3
class Solution:
    def romanToInt(self, s: str) -> int:
        char_dict = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
        i = len(s)-1
        rs = 0
        while True:
            if i<0:
                break
            if i == len(s)-1 or char_dict[s[i]] >= char_dict[s[i+1]]:
                rs += char_dict[s[i]]
            else:
                rs -= char_dict[s[i]]
            i -= 1
        return rs
```