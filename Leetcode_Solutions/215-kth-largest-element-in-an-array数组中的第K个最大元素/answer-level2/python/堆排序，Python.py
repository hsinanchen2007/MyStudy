```
class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        heap = nums[0:k]
        for i in range((k - 2) // 2, -1, -1):
            self.sift(heap, i, k - 1)
        for i in range(k, len(nums)):
            if nums[i] > heap[0]:
                heap[0] = nums[i]
                self.sift(heap, 0, k - 1)
        return heap[0]
    
    def sift(self,li, low, high):
        i = low
        j = 2 * i + 1
        temp = li[low]
        while j <= high:
            if j + 1 <= high and li[j + 1] < li[j]:
                j = j + 1
            if li[j] < temp:
                li[i] = li[j]
                i = j
                j = 2 * i + 1
            else:
                break
        li[i] = temp
```
没有借助库函数