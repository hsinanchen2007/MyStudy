### 解题思路


### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        sub = {}
        i, num = -1, 0
        for j in range(len(s)):
            if s[j] in sub:
                i = max(sub[s[j]], i)
                #这里的i标记的是字符串的起始位置已经匹配到哪个字符的位置了
                #因为有可能跟当前字符相同的字符的位置是出现在之前的
            num = max(num, j - i)
            sub[s[j]] = j
        return num
        #这里的num集合记录的是每个字符出现的位置
        #j - i表示两个相同字符之间的距离，就是当前子串的长度            
```