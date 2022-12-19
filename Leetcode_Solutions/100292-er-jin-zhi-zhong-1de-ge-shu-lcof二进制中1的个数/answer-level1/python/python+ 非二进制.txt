```
class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        k = 0 
        tmp_x = 0
        while tmp_x<n:
            tmp_x+=2**k
            k+=1
        count = 0
        while n>0:
            if n>=2**k:
                count+=1
                n = n-2**k
            else:
                n = n-0*2**k
            k-=1
        return count
        

    
         
```
代码块

