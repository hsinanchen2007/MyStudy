class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        import math
        for i in range(int(math.sqrt(c))+1):
            a=math.sqrt(c-i**2)
            if a%1==0:return True