### 解题思路
如题
### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        if s == '':
            return True
        l = [i for i in s]
        ans = []
        for i in range(len(l)):
            if l[i]=='(' or l[i]=='[' or l[i]=='{':
                ans.append(l[i])
            elif len(ans)>0 and l[i]=='}':
                if ans[-1]=='{':
                    ans.pop(-1)
                else:
                    return False
            elif len(ans)>0 and l[i]==']':
                if ans[-1]=='[':
                    ans.pop(-1)
                else:
                    return False
            elif len(ans)>0 and l[i]==')':
                if ans[-1]=='(':
                    ans.pop(-1)
                else:
                    return False
            else:
                return False
        if len(ans)==0:
            return True
        else:
            return False
```