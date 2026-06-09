![99e704b3479349e8906ee846f245567.png](https://pic.leetcode-cn.com/10195d09cf3dbeb9852b170c850549514550af59bbae9690a42d96bb6d5bc4a8-99e704b3479349e8906ee846f245567.png)
```python []
class Solution:
    def letterCasePermutation(self, S: str) -> List[str]:
        res = []
        def traceback(component, S):
            if S == '':
                res.append(component)
            else:
                if S[0].isalpha():
                    traceback(component + S[0].upper(), S[1:])
                    traceback(component + S[0].lower(), S[1:])
                else:
                    traceback(component + S[0], S[1:])
        
        traceback('', S)
        return res
```
