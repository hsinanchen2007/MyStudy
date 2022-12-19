### 解题思路
一次通过，不容易。

### 代码

```python3
class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        deck.sort()
        res = [deck[-1]]
        for i in range(len(deck)-2, -1, -1):
            res = [deck[i]] + [res.pop()] + res
        return res

```