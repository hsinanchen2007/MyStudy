```
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        good = list(set(words))
        good.sort(key=lambda x: len(x), reverse=True)
        tmpword = good.pop(0) + '#'
        while len(good) > 0:
            word = good.pop(0) + '#'
            if word not in tmpword:
                tmpword += word
        return len(tmpword)
```
