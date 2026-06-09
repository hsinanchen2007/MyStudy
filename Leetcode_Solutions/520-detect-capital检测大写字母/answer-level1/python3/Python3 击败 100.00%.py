好巧
```
class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if word.isupper() is True or word.islower() is True:
            return True
        if word[0].isupper():
            if len(word) == 1:
                return True
            return word[1:].islower()
```
