
```python3
class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:
        res = []
        n = len(S)
        def helper(start,tem):
            if len(tem) == n:
                res.append(tem)
                return
            for i in range(start,n):
                if ord(S[i])<58:   #9的ASCII码为57
                    tem+=S[i]
                    if len(tem)==n:
                        res.append(tem)
                        return
                    continue
                else:
                    helper(i+1,tem + (S[i].upper()))
                    helper(i+1,tem + (S[i].lower()))
            return
        helper(0,'')
        return list(set(res))
                
```