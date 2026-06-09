```
class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip()
        Words= s.split()
        start = 0
        end = len(Words) - 1
        while end - start >= 1:
            Words[end], Words[start] = Words[start], Words[end]
            start += 1
            end -= 1
        
        return ' '.join(Words)
```
