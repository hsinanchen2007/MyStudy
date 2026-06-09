### 解题思路
快速排序，时间复杂度O(N * log N)

### 代码

```python
class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if nums:
            def partition(left, right):
                flag = nums[left]
                index = left + 1
                i = index

                while i <= right:
                    if nums[i] > flag:
                        nums[index], nums[i] = nums[i], nums[index]
                        index += 1

                    i += 1

                nums[left], nums[index - 1] = nums[index - 1], nums[left]

                return index - 1

            def quick_sort(left, right):
                if left < right:
                    partition_index = partition(left, right)
                    quick_sort(left, partition_index - 1)
                    quick_sort(partition_index + 1, right)

            quick_sort(0, len(nums) - 1)

            return nums[k - 1]
        
        return -1
```