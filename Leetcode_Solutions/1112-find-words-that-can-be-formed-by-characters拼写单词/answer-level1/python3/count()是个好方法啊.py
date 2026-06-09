```
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        total=0
        for word in words:
            for s in word:
                if word.count(s) > chars.count(s):
                    break
            else:
                total += len(word)
        return total

```
