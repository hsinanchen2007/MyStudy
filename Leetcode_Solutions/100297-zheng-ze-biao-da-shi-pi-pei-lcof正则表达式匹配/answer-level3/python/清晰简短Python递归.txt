### 代码

```python3
class Solution:
    import functools
    @functools.lru_cache()
    def isMatch(self, s: str, p: str) -> bool:
        if not p:
            return not s
        first_match = bool(s) and p[0] in [s[0], '.']
        if len(p) >= 2 and p[1] == '*':
            # 如果发现有字符和 '*' 结合，或者匹配该字符 0 次，然后跳过 该字符 和 '*'
            # 或者当 p[0] 和 s[0] 匹配后，移动 s
            return self.isMatch(s, p[2:]) or (first_match and self.isMatch(s[1:], p))
        else:
            return first_match and self.isMatch(s[1:], p[1:])
```