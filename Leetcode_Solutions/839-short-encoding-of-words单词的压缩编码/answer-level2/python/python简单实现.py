python简单实现
```python
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        s = ''
        words = sorted(words, key=lambda x:len(x), reverse=True)
        for iterm in words:
            if iterm + '#' not in s:
                s = s + iterm + '#'
        return len(s)
```