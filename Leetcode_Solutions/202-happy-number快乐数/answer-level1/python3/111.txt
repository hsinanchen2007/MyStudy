def get_value1(m):
    val=[]
    ss=0
    i=0
    while m:
        val.append(m % 10)
        m = m // 10
    val.reverse()
    while i<=(len(val)-1):
        ss=ss+val[i]**2
        i+=1
    return ss
class Solution:
    def isHappy(self,n: int) -> bool:
        L=[4,16,37,58,89,149,145,42,20]
        s=get_value1(n)
        if s in L:
            return False
        while s not in L:
            s=get_value1(s)
            if s==1:
                return True
        return False