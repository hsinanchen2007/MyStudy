```
class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        display = sorted(deck,reverse=True)
        res=[]
        for i in display:
            res.append(i)
            if display.index(i) != len(display)-1:
                res.append(res.pop(0))
        res.reverse()
        return res
```