class Solution:
    def isMonotonic(self, A) -> bool:
        B = sorted(A)
        C = B[::-1]
        if A == B or A == C:
            return True
        else:
            return False