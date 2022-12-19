

### 代码

```python3
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:

        import collections

        ans = 0
        cnt = collections.Counter(chars)
        for w in words:
            c = collections.Counter(w)
            if all([c[i] <= cnt[i] for i in c]):
                ans += len(w)
        return ans


```