```
class Solution:
    def numSteps(self, s: str) -> int:
        if not s:return 0

        if s=='1':return 0
        if s[-1]=='0': 
            #步骤为1步
            return self.numSteps(s[:-1])+1
        else:
            #如果是1结尾为奇数  那说明要+1 ，并且s会变
            #步骤为2步
            len_s = len(s)
            s = list(s)
            more=True #位数是否会变多,例如 111 会变成1000
            for i in range(0,len_s):
                if s[len_s-i-1]=='0':
                    s[len_s-i-1]='1'
                    more=False
                    break
                else:
                    s[len_s-i-1]='0'
            if more:s.insert(0,'1')
            s =''.join(s)
            return self.numSteps(s[:-1])+2    
```
