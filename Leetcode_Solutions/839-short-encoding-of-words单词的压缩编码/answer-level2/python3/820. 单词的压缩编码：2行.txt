108ms

```python []
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words = sorted(w[:: -1] for w in words)
        return sum(map(len, words)) + len(words) - sum(len(words[i]) + 1 for i, w in enumerate(words[1: ]) if w.startswith(words[i]))
```