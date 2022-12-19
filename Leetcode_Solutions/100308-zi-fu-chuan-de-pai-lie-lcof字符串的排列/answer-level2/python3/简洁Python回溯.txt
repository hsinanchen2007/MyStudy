### 代码
```python3
class Solution:
    def permutation(self, s: str) -> List[str]:
        used = [False for _ in range(len(s))]
        res = []
        def backtrack(s, track):
            if len(track) == len(s):
                res.append(track)
                return
            for i in range(len(s)):
                if not used[i]:
                    if i > 0 and s[i] == s[i-1] and not used[i-1]:
                        continue
                    used[i] = True
                    backtrack(s, track + s[i])
                    used[i] = False
        backtrack(s, '')
        return list(set(res))    
```