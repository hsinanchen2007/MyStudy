```python
class Solution:
    def minSwap(self, A: List[int], B: List[int]) -> int:
        # non-zero length
        # A.B length <= 1000
        # A[i], B[i] <= 2000
    
        # Time complexity : O(N)
        # Space complexity: O(1)

        pre_ori, pre_rev = 0, 1
        for i in range(len(A) - 1, 0, -1):
            a, b = float('inf'), float('inf')
            if A[i] > A[i - 1] and B[i] > B[i - 1]:
                a = min(a, pre_ori) 
                b = min(b, pre_rev) + 1
            if A[i] > B[i - 1] and B[i] > A[i - 1]:
                a = min(a, pre_rev)
                b = min(b, pre_ori) + 1
            pre_ori = a
            pre_rev = b
        return min(pre_ori, pre_rev)
```