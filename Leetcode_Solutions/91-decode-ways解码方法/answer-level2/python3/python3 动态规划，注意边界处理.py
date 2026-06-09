 方法1：直接使用原函数递归（超时）
class Solution:
    def numDecodings(self, s: str) -> int:
        # print(s)
        n=len(s)
        if n==1 :
            if 0<int(s)<27:
                return 1
            else:
                return 0
        if n==2 :
            if 0<int(s)<=26 :
                if s[-1]!='0' and s[0]!='0':
                    return 2
                if s[-1]=='0' and s[0]!='0':
                    return 1
                else:
                    return 0
            elif s[-1]!="0" and s[0]!='0':
                return 1
            else:
                return 0
        if s[-1]=='0' :
            if s[-2]=='0':
                return 0
            elif 0<int(s[n-2:])<=26:
                return self.numDecodings(s[:n-2])
            else:
                return 0
        elif s[-2]!='0':
            if 0<int(s[n-2:n])<=26:
                return self.numDecodings(s[0:n-1])+self.numDecodings(s[0:n-2])
            else:
                return self.numDecodings(s[0:n-1])
        elif s[-2]=='0':
            return self.numDecodings(s[0:n-1])
    方法2：维持一个记忆数组：
```
class Solution:
    def numDecodings(self, s: str) -> int:
        # print(s)
        n=len(s)
        if n==0:
            return 0
        ans=[0 for _ in range(n)]
       
        if 0<int(s[0])<27:
            ans[0]= 1
        else:
            ans[0]= 0
        if n==1:
            return ans[-1]
        if 0<int(s[0:2])<=26 :
            if s[1]!='0' and s[0]!='0':
                ans[1]=2
            elif s[1]=='0' and s[0]!='0':
                ans[1]= 1
            else:
                ans[1]=0
        elif s[1]!="0" and s[0]!='0':
            ans[1]=1
        else:
            ans[1]=0
        for i in range(2,n):
            if s[i]=='0' :
                if 0<int(s[i-1:i+1])<=26:
                    ans[i]=ans[i-2]
                else:
                    ans[i]= 0
            elif s[i-1]!='0':
                if 0<int(s[i-1:i+1])<=26:
                    ans[i]=ans[i-1]+ans[i-2]
                else:
                    ans[i]=ans[i-1]
            elif s[i-1]=='0':
                ans[i]=ans[i-1]
        return ans[-1]
```
