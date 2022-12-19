```
class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        return words == sorted(words,key=lambda s:''.join(['abcdefghijklmnopqrstuvwxyz'[order.index(i)] for i in s]))
```