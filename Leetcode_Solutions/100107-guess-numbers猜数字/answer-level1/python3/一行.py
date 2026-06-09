```
class Solution:
    def game(self, guess: List[int], answer: List[int]) -> int:     
        return sum(i == j for i, j in zip(guess, answer))
```
