class Solution:
    def tribonacci(self, n: int) -> int:
        a, b, c = 0, 1, 1
        if n == 0: 
            return 0
        if n == 1: 
            return 1
        if n == 2: 
            return 1

        for i in range(3, n+1):
            d = a+b+c
            a = b
            b = c
            c = d
        return c