```
class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        if deck.__len__()<=1:
            return deck
        deck_sorted=sorted(deck,reverse=True)
        new_list=[]
        for i in range(deck_sorted.__len__()):
            if new_list==[]:
                new_list.append(deck_sorted[i])
            else:
                new_list.insert(0,new_list.pop(-1))
            # new_list.insert(0,deck_sorted[i])
                new_list.insert(0,deck_sorted[i])
        return new_list
```
