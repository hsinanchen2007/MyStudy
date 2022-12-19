





- class Solution:
    def isHappy(self, n: int) -> bool:
        lis=list(str(n))
        a=0
        for i in range(len(lis)):
            b=int(lis[i])

            a+=b*b

        if a!=1 and a!=4:
            return self.isHappy(a)
        if a==4:
            return False
        if a==1:
            return True