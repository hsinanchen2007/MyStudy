class Solution(object):
    def addBinary(self, a, b):
        i=1
        l=len(a)-1
        num=0
        while l>=0:
            num+=int(a[l])*i
            i=i+i
            l-=1
        l=len(b)-1
        i=1
        while l>=0:
            num+=int(b[l])*i
            i=i+i
            l-=1
        s=str(bin(num))
        return s[2:]

