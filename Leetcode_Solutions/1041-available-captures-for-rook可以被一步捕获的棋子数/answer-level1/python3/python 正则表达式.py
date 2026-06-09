直接两个方向找`p\.*R`和`R\.*p`就行
```
import re
class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        res=0
        for i in board+list(zip(*board)):
            s=''.join(i)
            res+=bool(re.search(r'p\.*R',s))
            res+=bool(re.search(r'R\.*p',s))
        return res
```
