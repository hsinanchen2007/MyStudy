class Solution:
    def flipAndInvertImage(self, A: List[List[int]]) -> List[List[int]]:
        m=len(A);
        n=len(A[0]);
        for i in range(m):
            for j in range(n):
                A[i][j]^=1;
        return [i[::-1] for i in A];