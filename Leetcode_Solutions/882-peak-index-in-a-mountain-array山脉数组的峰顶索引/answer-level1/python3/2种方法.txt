class Solution:
    def peakIndexInMountainArray(self, A: List[int]) -> int:
        # 方法一：暴力法
        # length = len(A)
        # i = 0
        # while i < length - 1:
        #     if A[i] < A[i + 1]:
        #         i += 1
        #     else:
        #         return i

        # 方法二：二分法
        length = len(A)
        left, right = 0, length - 1
        while left < right:
            mid = (left + right) // 2
            if A[mid] < A[mid + 1]:
                left = mid + 1
            else:
                right = mid
        
        return left