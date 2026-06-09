class Solution:
    def divisorGame(self, N: int) -> bool:
        a = 0
        for x in range(1,N):
            N % x == 0  
            a += 1
        return (False if a % 2 == 0 else True)