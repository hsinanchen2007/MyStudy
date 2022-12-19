
```python []
def is_complete(s):
    res = 0
    for x in s:
        if x == '(':
            res +=1
        if x == ')':
            res -=1
        if res <0:
            return False
    return res == 0

class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        number_of_complete = 0
        temp = 0
        left = 0
        right = 0
        for x in s:
            if x == '(':
                left +=1
                temp +=1
            elif x == ')':
                right +=1
                if temp > 0:
                    number_of_complete+=1
                    temp-=1
        left_to_remove = left-number_of_complete
        right_to_remove = right-number_of_complete
        
        res = {s}
        
        while left_to_remove:
            left_to_remove -= 1
            new_res = set()
            for x in res:
                for i in range(len(x)):
                    if x[i] == '(':
                        new_res.add(x[:i]+x[i+1:])
            res = new_res
        
        while right_to_remove:
            right_to_remove -= 1
            new_res = set()
            for x in res:
                for i in range(len(x)):
                    if x[i] == ')':
                        new_res.add(x[:i]+x[i+1:])
            res = new_res
        return [x for x in res if is_complete(x)]
    
                
                
```

