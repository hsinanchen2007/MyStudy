`
class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n<=0:
            return False
        dd=False 

        sumk=1

        while sumk <= n:

            if sumk==n:
                dd=True
                break

            sumk=sumk*3

        return dd

`


