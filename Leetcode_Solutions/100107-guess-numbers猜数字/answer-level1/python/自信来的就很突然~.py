```
class Solution:
    def game(self, guess: List[int], answer: List[int]) -> int:
        cnt = 0
        for i,j in zip(guess, answer):
            if i == j:
                cnt += 1
        return cnt
```

