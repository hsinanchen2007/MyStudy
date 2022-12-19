```python
class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        if not s:
            return ''
        return ' '.join(c for c in s.split(' ')[::-1] if c).strip()
```