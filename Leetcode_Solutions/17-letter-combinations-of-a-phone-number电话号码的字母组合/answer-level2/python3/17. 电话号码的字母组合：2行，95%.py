
```python []
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        d = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
        return digits and map(''.join, itertools.product(*(d[i] for i in digits)))
```

![image.png](https://pic.leetcode-cn.com/c3218c1da3598966cbac53dc44899da75fb550704cea5db4e5ebd17d7d6a775d-image.png)
