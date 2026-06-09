```
class Solution:
    def permutation(self, S: str) -> List[str]:
        if len(S) == 1:
            return [S]
        count = collections.Counter(list(S))
        chars = dict(count).keys()
        ans = []
        for ch in chars:
            count[ch] -= 1
            res = self.permutation(''.join(count.elements()))
            count[ch] += 1
            ans.extend([ch + sub for sub in res])
        return sorted(ans)
```
