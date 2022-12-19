```
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:return []#特殊情况
        def func(s,res):
            if not s:return res
            dic={'2':'abc','3':'def','4':'ghi','5':'jkl','6':'mno','7':'pqrs','8':'tuv','9':'wxyz'}
            res0 = []
            for i in res:
                for j in dic[s[0]]:
                    res0.append(i+j)
            return func(s[1:],res0)
        return func(digits,[''])
```
