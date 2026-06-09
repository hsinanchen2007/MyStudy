```python
class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip(' ')
        s_arr = s.split(' ')
        return ' '.join([s for s in s_arr if s != ''][::-1])
```