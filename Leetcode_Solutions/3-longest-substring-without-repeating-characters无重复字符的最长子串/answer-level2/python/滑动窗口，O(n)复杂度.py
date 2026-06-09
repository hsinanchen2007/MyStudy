### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        max_len = 0
        left = 0
        right = 0
        char_dict = {}
        for right in range(0, len(s)):
            if s[right] in char_dict and char_dict[s[right]] >= left: 
                if max_len < right - left:
                    max_len = right - left               
                left = char_dict[s[right]] + 1
            else:
                 if max_len < right - left + 1:
                     max_len = right - left + 1
            char_dict[s[right]] = right
        return max_len
```