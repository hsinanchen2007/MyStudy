### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        p ={}
        res = 0
        j=0
        for i in range(len(s)):
            if s[i] in p:
                j = max(p[s[i]],j)
            p[s[i]] = i+1
            res = max(res,i-j+1)
        return res
```