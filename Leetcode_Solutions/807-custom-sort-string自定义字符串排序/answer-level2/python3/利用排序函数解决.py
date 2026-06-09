```
class Solution:
    def customSortString(self, S: str, T: str) -> str:
        S_set = {i:index for index,i in enumerate(S)}
        result = []
        for index,i in enumerate(T):
            if i in S_set:
                result.append((i,S_set[i]))
            else:
                result.append((i, index+26))
        result_ = sorted(result, key= lambda x:x[1])
        return "".join(i for i,j in result_)
```
