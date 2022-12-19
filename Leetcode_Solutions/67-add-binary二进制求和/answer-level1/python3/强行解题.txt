class Solution:
    def addBinary(self, a: str, b: str) -> str:
        if len(b)>len(a):
            a,b=b,a
        b='0'*(len(a)-len(b))+b
        k=0
        t=""
        m=0
        for i in range(len(a)-1,-1,-1):            
            m=int(a[i])+int(b[i])
            if m==2:
                m=0
                m=k+m
                k=1
            else:
                m=k+m
                k=0
                if m==2:
                    m=0
                    k=1          
            t=str(m)+t
        if i==0 and k==1:
            t=str(k)+t
        return t