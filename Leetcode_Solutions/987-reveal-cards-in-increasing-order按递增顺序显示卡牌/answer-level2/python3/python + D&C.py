```python
class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        if len(deck) == 1: return deck
        ans = [0] * len(deck)
        deck.sort() # O(NlogN)
        def roll_back(arr, cnt): # O(N)
            arr = collections.deque(arr)
            for i in range(cnt):
                tail = arr[-1]
                arr.pop() # O(1)
                arr.appendleft(tail) # O(1)
                # or arr is list and arr = [arr[-1]] + arr[:-1]
            return list(arr)
        half = (len(deck) + 1) // 2 # half =  4
        for i in range(half):
            ans[i * 2] = deck[i]
        rest = self.deckRevealedIncreasing(deck[half:])
        rest = roll_back(rest, half)
        for i in range(len(rest)):
            ans[i * 2 + 1] = rest[i]
        return ans
```