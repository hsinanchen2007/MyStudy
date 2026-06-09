```
class Solution:
    def game(self, guess: List[int], answer: List[int]) -> int:
        return sum([1 if guess[i] == answer[i] else 0 for i in range(len(guess))])

```
