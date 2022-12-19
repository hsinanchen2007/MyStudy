```
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        sum=0
        for x in words:
            point=0
            for i in x:
                if x.count(i)>chars.count(i):
                    point=1
            if point==0:
                sum+=len(x)
        return sum
```