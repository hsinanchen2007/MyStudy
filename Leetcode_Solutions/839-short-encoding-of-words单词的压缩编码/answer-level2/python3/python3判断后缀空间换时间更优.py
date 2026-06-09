直接在set中遍历而不在list中遍历
```
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        good = set(words)
        fli = set(words)
        for word in good:
            for k in range(1, len(word)):
                fli.discard(word[k:])

        return sum(len(word) + 1 for word in fli)

```
