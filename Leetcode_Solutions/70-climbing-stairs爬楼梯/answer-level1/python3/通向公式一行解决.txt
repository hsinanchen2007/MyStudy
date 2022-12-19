class Solution:
    def climbStairs(self, n: int) -> int:
        return int((1/5**0.5)*(((1+5**0.5)/2)**(n+1)-((1-5**0.5)/2)**(n+1))+0.5)