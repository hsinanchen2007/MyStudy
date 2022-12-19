class Solution:
    def sumOfDigits(self, A: List[int]) -> int:
        Min=A[0]
        for i in range(len(A)):
            if Min>A[i]:
                Min=A[i]
        S=Min%10
        c=Min%10
        if Min>=10:
            while Min!=c:
                Min=Min//10
                c=Min%10
                S+=c                
        if S%2:
            return 0
        else:
            return 1