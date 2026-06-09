```python []
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        c_ct = collections.Counter(chars)
        return sum(
            all(w_ct[c] <= c_ct[c] for c in word) and len(word)
            for word, w_ct in zip(words, map(collections.Counter, words))
        )
```

```python []
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        c_ct = collections.Counter(chars)
        def f(w):
            w_ct = collections.Counter(w)
            return all(w_ct[c] <= c_ct[c] for c in w)
        return sum(map(len, filter(f, words)))
```
```python []
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        ans, c_ct = 0, collections.Counter(chars)
        for word in words:
            w_ct = collections.Counter(word)
            ans += all(w_ct[c] <= c_ct[c] for c in word) * len(word)
        return ans
```
