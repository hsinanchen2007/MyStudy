class Solution(object):
    def waysToStep(self, n):
        """
        :type n: int
        :rtype: int
        """
        a1=1
        a2=2
        a3=4
        if n==1:
           return a1
        if n==2:
            return a2
        if n==3:
            return a3
        temp=0
        for i in range(4,n+1):
            temp=(a1+a2+a3)%1000000007
            a1=a2
            a2=a3
            a3=temp
        return temp