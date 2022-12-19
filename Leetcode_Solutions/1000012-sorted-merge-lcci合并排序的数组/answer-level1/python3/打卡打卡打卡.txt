class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        cur, indA, indB = m + n - 1, m - 1, n - 1

        while cur >= 0:
            if indA >= 0 and indB >= 0:
                if A[indA] >= B[indB]:
                    A[cur] = A[indA]
                    indA -= 1
                else:
                    A[cur] = B[indB]
                    indB -= 1
            elif indA >= 0:
                A[cur] = A[indA]
                indA -= 1
            else:
                A[cur] = B[indB]
                indB -= 1

            cur -= 1