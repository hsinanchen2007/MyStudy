```
class Solution:
    def customSortString(self, S: str, T: str) -> str:
        dicStoI = {}
        dicItoS = {}

        for i in range(len(S)):
            dicStoI[S[i]] = chr(i + 65)
            dicItoS[chr(i + 65)] = S[i]
        result = []
        for j in range(len(T)):
            if T[j] in dicStoI.keys():
                result.append(dicStoI[T[j]])
            else:
                result.append(T[j])
        result = sorted(result)
        Strresult = ''
        for k in range(len(result)):
            if result[k] in dicItoS.keys():
                Strresult += dicItoS[result[k]]
            else:
                Strresult += result[k]
        return Strresult

        
        

```
