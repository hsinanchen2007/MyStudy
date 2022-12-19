```
class Solution:
    def reverseWords(self, s: str) -> str:
        tmp = s.split()
        i = 0
        j = len(tmp) - 1
        while i <= j:
            tmp[i], tmp[j] = tmp[j], tmp[i]
            i += 1
            j -= 1
        return ' '.join(tmp)
```
