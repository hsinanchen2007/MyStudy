### 解题思路
说实话，这题的判定逻辑本来就有问题。

思路就是排除掉所有不对的情况，然后根据这题的设定，再打一些补丁

### 代码

```python3
class Solution:
    def isNumber(self, s):
        s=s.strip()
        if not s:
            return False
        num=['0','1','2','3','4','5','6','7','8','9']
        temp=s[0]
        if temp in num:
            return self.Normal(s)
        elif temp=='e':
            return False
        elif temp=='+' or temp=='-':
            if len(s)==2 and (not s[1] in num):
                return False
            return self.Normal(s[1:])
        elif temp=='.':
            if len(s)==1:
                return False
            elif s[1]=='e':
                return False
            return self.db(s[1:])
        else:
            return False
    
    def Normal(self,s):
        if not s:
            return False
        if s[0]=="e":
            return False
        ls=len(s)
        num=['0','1','2','3','4','5','6','7','8','9']
        for i in range(ls):
            temp=s[i]
            if temp in num:
                continue
            elif temp=='e':
                return self.eb(s[i+1:])
            elif temp=='.':
                return self.db(s[i+1:])
            else:
                return False
        return True
            
    def eb(self,s):
        if not s:
            return False
        if s[0]=='+' or s[0]=='-':
            s=s[1:]
            if not s:
                return False
        ls=len(s)
        num=['0','1','2','3','4','5','6','7','8','9']
        for i in range(ls):
            temp=s[i]
            if not (temp in num):
                return False
        return True
            
    def db(self,s):
        if not s:
            return True
        ls=len(s)
        num=['0','1','2','3','4','5','6','7','8','9']
        for i in range(ls):
            temp=s[i]
            if temp=='e':
                return self.eb(s[i+1:])
            elif temp in num:
                continue
            else:
                return False
        return True
```