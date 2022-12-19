先算出长度的最大公约数，然后穷举。
```
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        def gcd(m,n):
            if m==0:
                return n
            if m==1:
                return 1
            if m>n:
                return gcd(n,m)
            else:
                return gcd(n%m,m)
        b=gcd(len(str1),len(str2))
        i=b
        while i>0:
            if b%i==0:
                if str1[:i]==str2[:i] and str1[:i]*(len(str1)//i)==str1 and str2[:i]*(len(str2)//i)==str2:
                    return str1[:i]
            i-=1
        return ""
```

直接对字符串做辗转相除
```
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if(len(str2)>len(str1)):
            return self.gcdOfStrings(str2,str1)
        s=str1.replace(str2,"")
        if s=="":
            return str2
        elif s==str1:
            return ""
        else:
            return self.gcdOfStrings(str2,s)
```
