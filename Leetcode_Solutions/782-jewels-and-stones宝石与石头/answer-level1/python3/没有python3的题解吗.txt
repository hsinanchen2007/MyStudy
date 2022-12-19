效率不是很高但是通过了 =  =
```Python []
class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        for s in set(S).difference(set(J)):
            S = S.replace(s,'')
        return len(S)
```