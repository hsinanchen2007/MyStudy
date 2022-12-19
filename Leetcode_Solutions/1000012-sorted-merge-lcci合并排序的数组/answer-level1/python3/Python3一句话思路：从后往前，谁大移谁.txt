本题是两路归并的简单变形，要求in-place的把短数组B归并到长数组A中。
回忆基本两路归并的规则：双指针，从前往后，谁小移谁。
本题的规则就是：双指针，从后往前，谁大以谁，直接把结果存在数组A中。
T(N) = O(m + n)
S(N) = O(1)
```
class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify A in-place instead.
        """
        i = m - 1
        j = n - 1
        k = m + n - 1
        while i >= 0 and j >= 0:
            if A[i] > B[j]:
                A[k] = A[i]
                i -= 1
            else:
                A[k] = B[j]
                j -= 1
            k -= 1
        while j >= 0:
            A[k] = B[j]
            k -= 1
            j -= 1
```
