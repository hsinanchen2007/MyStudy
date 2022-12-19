

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        mystack=[]
        for c in s:
            if c in {'(','{','['}:
                mystack.append(c)
            elif c in {')','}',']'}:
                if not mystack:
                    return False
                elif c==')' and mystack[-1]=='(':
                    mystack.pop()
                elif c=='}' and mystack[-1]=='{':
                    mystack.pop()
                elif c==']' and mystack[-1]=='[':
                    mystack.pop()
                else:
                    return False
        return False if mystack else True
```