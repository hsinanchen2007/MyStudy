class Solution:
    def repeatedStringMatch(self, A: str, B: str) -> int:
        base_num = len(B)//len(A)
        A_new = A*base_num
        if B in A_new:return base_num
        if B in A_new+A:return base_num+1
        if B in A_new+A+A:return base_num+2
        return -1