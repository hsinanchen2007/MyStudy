### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) <=1:
            return len(s)
        left, right = 0, 1
        res = 0
        while right<len(s):
            if s[right] in s[left:right]:
                res = max(res, right-left)
                left += 1
                right = left + 1
            else:
                right += 1
        return max(res, right-left)
```