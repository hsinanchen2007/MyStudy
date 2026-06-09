```
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []
        parenthesis = ['(', ')']
        
        def back_track(parenthesis, combination, m, balance, result):
            if m == 0:
                if balance == 0:
                    result.append(combination)
            else:
                for i in parenthesis:
                    if balance >= 0:
                        if i == '(':
                            back_track(parenthesis, combination+i, m-1, balance+1, result)
                        else:
                            back_track(parenthesis, combination+i, m-1, balance-1, result)
        
        back_track(parenthesis, "", n*2, 0, result)
        return result
```
