
```python []
class Solution:
    def masterMind(self, solution: str, guess: str) -> List[int]:
        a = sum(i == j for i, j in zip(solution, guess))
        b = sum((collections.Counter(solution) & collections.Counter(guess)).values())
        return [a, b - a]
```