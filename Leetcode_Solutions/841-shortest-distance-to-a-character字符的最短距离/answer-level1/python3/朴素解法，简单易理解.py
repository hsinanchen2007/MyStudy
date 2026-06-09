```
class Solution:
    def shortestToChar(self, S: str, C: str) -> List[int]:
        result=[]
        sLen=len(S)
        index=S.index(C)
        for i in range(sLen):
            if S[i]==C:
                result.append(0)
                index=i
            else:
                if S[i:].find(C)==-1:
                    result.append(i-index)
                else:
                    index_2_c=S[i:].index(C)+i
                    result.append(min(abs(i-index),abs(i-index_2_c)))
        return result
```
