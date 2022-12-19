1.split
2.zip(text, text[1:], text[2:])
3.列表推导式
```
class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        text = text.split()
        return [trd for fst, sed, trd in zip(text, text[1:], text[2:]) if fst == first and sed == second]
```
