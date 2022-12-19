```python
class Solution:
    def findLongestWord(self, s: str, d: List[str]) -> str:
        d.sort(key = lambda x: (-len(x), x))
        for word in d:
            cnt, flag = 0, True
            for ch in word:
                if ch not in s[cnt:]:
                    flag = False
                    break
                else:
                    index = s[cnt:].index(ch) + cnt
                    cnt = index + 1
            if flag: return word
        return ''
```