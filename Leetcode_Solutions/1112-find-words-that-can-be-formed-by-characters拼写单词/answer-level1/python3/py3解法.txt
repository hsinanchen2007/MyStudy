思路：
使用collections.Counter简化代码
```
class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        r = 0
        cnt = collections.Counter(chars)
        for w in words:
            c = collections.Counter(w)
            if all([c[i] <= cnt[i] for i in c]):
                r += len(w)
        return r
```
