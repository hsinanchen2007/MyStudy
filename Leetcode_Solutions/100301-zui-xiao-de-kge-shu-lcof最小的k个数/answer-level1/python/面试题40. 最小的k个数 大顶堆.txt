### 解题思路
1. 基于堆的方法，思路同书。

### 代码

```python
class Solution(object):
    def getLeastNumbers(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """
        def HeapAdjust(nums, s, n):
            """
            堆排序核心，调整nums[s], 使其成为一个大顶堆
            """
            temp = nums[s]
            j = 2*s + 1
            while j < n:
                if (j + 1 < n) and nums[j] < nums[j+1]:
                    j += 1
                if temp >= nums[j]:
                    break
                nums[s] = nums[j]
                s = j
                j = 2*j + 1
            nums[s] = temp

        def LeastNumbers(nums, k):
            """
            解法二：使用堆或红黑树做容器，时间复杂度O(nlogk), 不会改变数据，可以处理数据流
            这里使用大顶堆
            """
            if k < 1: return []
            n = len(nums)
            if k >= n: return nums

            heap = nums[:k]
            for i in range(k//2, 0, -1):
                HeapAdjust(heap, i-1, k)

            for i in range(k, n):
                if nums[i] < heap[0]:
                    heap[0] = nums[i]
                    HeapAdjust(heap, 0, k)

            return heap
        
        return LeastNumbers(arr, k)

```