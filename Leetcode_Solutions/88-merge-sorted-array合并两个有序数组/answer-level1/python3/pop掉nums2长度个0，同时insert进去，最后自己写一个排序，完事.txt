class Solution:

    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:

        """
        Do not return anything, modify nums1 in-place instead.
        """
        length = len(nums2)
        for i in range(length):
            nums1.insert(0,nums2[i])
            nums1.pop()
        
        def sort(arr):
            for i in range(len(arr)-1):
                for j in range(len(arr)-1-i):
                    if arr[j] > arr[j+1]:
                        arr[j],arr[j+1] = arr[j+1],arr[j]
            return arr
        
        return sort(nums1)