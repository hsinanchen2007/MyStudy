### 解题思路
> 在遍历字符串时，将unique子串记录下来，遇到在unique子串中出现的字符，更新最大unique子串长度，并只保留unique子串中该字符之后的子串作为新的unique子串。

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        uniq_chars = ""
        max_length = 0
        for c in s:
            if c in uniq_chars:
                max_length = max(len(uniq_chars), max_length)
                uniq_chars = uniq_chars[uniq_chars.index(c) + 1:]
            uniq_chars += c
        return max(max_length, len(uniq_chars))
```