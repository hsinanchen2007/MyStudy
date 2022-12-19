### 解题思路
前后各一个指针 框出候选子串

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s == '':
            return 0
        if s == ' ':
            return 1
        l = len(s)
        start, end = 0, 0
        max_len = 0
        while end<(l+1):
            sub_str = s[start:end]
            if len(set(i for i in sub_str)) == len(s[start:end]):
                max_len = max(max_len,len(s[start:end]))
                end += 1
            else:
                start += 1
        return max_len
            
```