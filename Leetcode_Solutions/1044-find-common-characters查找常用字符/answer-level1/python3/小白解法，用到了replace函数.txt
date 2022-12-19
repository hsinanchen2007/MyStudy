```
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        List=[]
        for s in A[0]:
            for i in range(1,len(A)):
                if s not in A[i]:
                    break
                else:
                    A[i]=A[i].replace(s,'',1)
            else:
                List.append(s)
        return List
```
repalce返回A[i]的副本，用''去取代已经被用过的字符串s
