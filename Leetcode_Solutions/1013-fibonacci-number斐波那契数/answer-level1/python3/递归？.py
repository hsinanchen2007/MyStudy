class Solution(object):
    def fib(self, N):
        """
        :type N: int
        :rtype: int
        """
        
  
        n,a,b = 0,0,1
        while n<N:
            a,b = b, a+b
            n+=1
            
        return a