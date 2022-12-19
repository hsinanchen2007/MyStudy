```python
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        from itertools import product
        l = '- - abc def ghi jkl mno pqrs tuv wxyz'.split()
        return [''.join(c) for c in product(*[l[int(i)] for i in digits])] if digits else []
```
- 本题相当于求解笛卡尔积