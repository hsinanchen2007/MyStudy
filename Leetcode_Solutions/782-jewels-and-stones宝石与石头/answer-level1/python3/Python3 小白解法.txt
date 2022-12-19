```
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        return sum(S[i] in J for i in range(len(S)))
```

