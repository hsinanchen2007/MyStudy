### 解题思路
官方提供的回溯法，关键在于\*如何使用，其中\*可以有0或多个重复字符的情况，0这种情况需单独考虑。终止条件是模式串已经完结，但匹配串还没有穷尽。

### 代码

```python3
class Solution(object):
    def isMatch(self, text, pattern):
        if not pattern:
            return not text

        first_match = bool(text) and pattern[0] in {text[0], '.'}

        if len(pattern) >= 2 and pattern[1] == '*':
            return (self.isMatch(text, pattern[2:]) or
                    first_match and self.isMatch(text[1:], pattern))
        else:
            return first_match and self.isMatch(text[1:], pattern[1:])
```