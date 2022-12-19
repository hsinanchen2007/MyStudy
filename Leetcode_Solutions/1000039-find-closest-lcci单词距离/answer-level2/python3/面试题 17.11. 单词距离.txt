
```python []
class Solution:
    def findClosest(self, words: List[str], word1: str, word2: str) -> int:
        ans, i1, i2 = float('inf'), -float('inf'), -float('inf')
        for i, word in enumerate(words):
            if word == word1:
                ans = min(ans, i - i2)
                i1 = i
            if word == word2:
                ans = min(ans, i - i1)
                i2 = i
        return ans
```