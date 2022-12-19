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
        if not s: return 0
        lookup = set()
        max_len, cur_len = 0, 0
        left = 0
        for i in range(len(s)):
            cur_len += 1
            while s[i] in lookup:
                lookup.remove(s[left])
                left += 1
                cur_len -= 1
            lookup.add(s[i])
            max_len = cur_len if cur_len > max_len else max_len
        return max_len
```