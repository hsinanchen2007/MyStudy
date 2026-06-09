![image.png](https://pic.leetcode-cn.com/a9c6f9c2c502cf54d2e79f409c734821505c9c5a66ad9e7b8f814493125cc3b2-image.png)

 class Solution(object):
        def tribonacci(self, n):
            """
            :type n: int
            :rtype: int
            """
            if n==0:
                return 0
            elif n==1 :
                return 1
            elif n==2:
                return 1
                
            left=0
            middle=1
            right=1
            for i in range(3,n+1):
                left,middle,right=middle,right,left+middle+right
            return right

