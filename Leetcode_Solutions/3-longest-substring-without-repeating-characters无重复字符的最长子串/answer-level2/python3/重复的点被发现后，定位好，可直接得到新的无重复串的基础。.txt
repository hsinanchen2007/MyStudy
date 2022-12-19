### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        st = 0;
        maxlen = 0;
        cnter = 0;
        for i, c in enumerate(s):
            if c in s[st:i]:
                maxlen = max(maxlen, cnter)
                idxold = s[st:i].find(s[i])
                st += idxold + 1
                cnter = i - st + 1
            else:
                cnter += 1
        maxlen = max(maxlen, cnter)
        return maxlen
```