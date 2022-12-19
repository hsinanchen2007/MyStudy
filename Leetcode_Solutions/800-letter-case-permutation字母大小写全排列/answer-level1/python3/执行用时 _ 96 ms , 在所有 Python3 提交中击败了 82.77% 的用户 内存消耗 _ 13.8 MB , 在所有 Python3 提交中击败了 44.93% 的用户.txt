```
import string

class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:
        if not S:
            return []
        res = ['']
        for i in S:
            temp = []
            for j in res:
                if i in string.ascii_letters:
                    temp.append(j + i.upper())
                    temp.append(j + i.lower())
                else:
                    temp.append(j + i)
            res = temp
        return res
```



