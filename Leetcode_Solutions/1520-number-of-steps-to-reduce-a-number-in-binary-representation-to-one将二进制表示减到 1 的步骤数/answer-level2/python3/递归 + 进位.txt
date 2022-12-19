```
class Solution:
    def numSteps(self, s: str) -> int:
        if s == '1': return 0
        if s[-1] == '0': return 1 + self.numSteps(s[:-1])
        return 1 + self.numSteps(self.add_one(s))

    def add_one(self, s:str):
        str_ls,flag = list(s), 1
        for i in range(len(s)-1,-1,-1):
            if flag:
                if str_ls[i] == '1': 
                    str_ls[i] = '0'
                else:
                    str_ls[i] = '1'
                    flag = 0
            else:
                break
        return '1' + ''.join(str_ls) if flag else ''.join(str_ls)
```
