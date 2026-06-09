### 解题思路


### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        kind=len(set(s))
        if kind==1 :
            return 1
        if s=='':
            return 0
        for i in range(kind,1,-1):
            for j in range(len(s)):
                if len(set(s[j:j+i]))==i:
                    return i




```