Python3
方法一：直接排序，找出 len(nums)-k 的地方。时间复杂度 O(nlogn)。
方法二：对排序，维护一个大小为k的最小堆，当入堆一个元素后，堆的大小大于k了，就把堆顶元素pop出去，等遍历完nums中的所有元素后，堆顶就是第K大的元素。上代码

```python
import heapq
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        if not nums:
            return None
        heap = []
        heapq.heapify(heap)
        for num in nums:
            heapq.heappush(heap, num)
            if len(heap) > k:
                heapq.heappop(heap)
        return heap[0]
            
```
方法三：鉴于快速排序的特点，每一次确定一个元素在排序中的最终元素（这个元素也是每次的枢轴元素(pivot)），而第K大的元素，在排序好的数组中的下标就是len(nums)-k。所以在快速排序的过程中，我们每次判断此次确定的枢轴元素是在len(nums)-k位置元素的左边还是右边从而来缩小一半规模的元素，这样可以把时间复杂度从普通O(nlogn)，具体的时间复杂度的这里简单做个计算，第一次快排，数据规模是n，在确定枢轴元素的过程中，元素会互相比较n-1次，同理，第二次数据规模划分为一半后比较次数是 n/2 -1，第三次是n^2/2-1，直到0次，所以总次数加起来是(n-1+n/2-1+n^2/2-1+.....+0) = 2n-2-logn。所以说时间复杂度是O(n的)。
不过还有一个重要的点，就是随记选择枢轴元素，否则有序的数组可能会导致时间复杂度退化成O(n^2)。这题如果不用随记枢轴元素还是退化很严重的，特别慢。上代码：

```python
from random import randint
class Solution:
    def findKthLargest(self, nums, k: int) -> int:
        if not nums:
            return None
        return self.quickSort(nums, k, 0, len(nums) - 1)

    def quickSort(self, nums, k, low, high):
        i = low
        j = high
        pivotIndex = randint(i, j)
        nums[i], nums[pivotIndex] = nums[pivotIndex], nums[i]
        pivot = nums[i]
        while i < j:
            while i < j and nums[j] >= pivot:
                j -= 1
            if i < j:
                nums[i] = nums[j]
                i += 1
            while i < j and nums[i] < pivot:
                i += 1
            if i < j:
                nums[j] = nums[i]
                j -= 1
        nums[i] = pivot
        if i == len(nums) - k:
            return nums[i]
        elif i < len(nums) - k:
            return self.quickSort(nums, k, i + 1, high)
        else:
            return self.quickSort(nums, k, low, i - 1)
```


