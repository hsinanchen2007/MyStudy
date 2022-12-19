```
class Solution:
    def isValid(self, s: str) -> bool:
        li = 0
        strlist = [0]*len(s)
        for item in s:
            if item == '(' or item == '{' or item == '[':
                strlist[li]=item
                li+=1
            elif item == ')' and li != 0:
                if strlist[li-1] == '(':
                    li-=1
                else:
                    return False
            elif item == '}' and li != 0:
                if strlist[li-1] == '{':
                    li-=1
                else:
                    return False
            elif item == ']' and li != 0:
                if strlist[li-1] == '[':
                    li-=1
                else:
                    return False
            else:
                return False
        if li==0:
            return True
        else:
            return False
```
