```
class Solution:
    def addToArrayForm(self, A: List[int], K: int) -> List[int]:
        return [int(j) for j in str(int("".join([str(i) for i in A]))+K)]
```
