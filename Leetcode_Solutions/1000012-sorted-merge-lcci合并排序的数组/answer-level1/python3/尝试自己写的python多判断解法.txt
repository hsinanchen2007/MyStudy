class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        new_list = []
        a = b = 0
        while True:
            if a == m:
                A[:] = new_list + B[b:n]
                break
            elif b == n:
                A[:] = new_list + A[a:m]
                break
            elif A[a] <= B[b]:
                new_list.append(A[a])
                a = a + 1
            elif A[a] > B[b]:
                new_list.append(B[b])
                b = b + 1
            else:
                A[:] = new_list
                break
        return A