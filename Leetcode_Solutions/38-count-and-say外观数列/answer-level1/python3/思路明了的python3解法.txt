class Solution:
    def countAndSay(self,n):
        str = "11"
        if n==1:
            return "1"
        for i in range(1,n-1):
            str=self.countsay(str)
        return str
    def countsay(self,s):
        k=0
        ls=[]
        for N in range(1,len(s)):
            k+=1
            if  s[N]!=s[N-1]:
                ls.append(str(k))
                ls.append(s[N-1])
                k=0
        k+=1
        ls.append(str(k))
        ls.append(str(s[N]))
        s=''.join(ls)
        return s
简洁明了的思路，对上一个人的操作进行运算然后反复迭代