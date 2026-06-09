class Solution(object):
    def climbStairs(self, n):
        if n == 1:
            return 1
        if n == 2:
            return 2
        l1 = 1
        l2 = 2
        while(n>2):
            l1, l2 = l2, l1+l2
            n -= 1
        return l2
