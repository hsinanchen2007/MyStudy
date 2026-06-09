```
class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip()
        if s == '':
            return ''
        words = [i for i in s.split(' ') if len(i.strip()) > 0]
        words = ' '.join(words[::-1]) # 记得先反转再按空格拼接
        return words
```
