```
class Solution(object):
    def sortArrayByParityII(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        A.sort(key = lambda x: x%2)
        low = 1
        high = len(A)-1-1
        while low < high:
            mid = A[low]
            A[low] = A[high]
            A[high] = mid
            low += 2
            high -= 2
        return A
```
