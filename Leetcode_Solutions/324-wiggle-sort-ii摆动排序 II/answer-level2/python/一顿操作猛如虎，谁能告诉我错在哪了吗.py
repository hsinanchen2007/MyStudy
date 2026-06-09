### 解题思路
quick sort + 荷兰国旗 + 虚指针，输出还不如直接排序+额外申请空间
![image.png](https://pic.leetcode-cn.com/344113cf008ce9a6929e3a05889a5f2f6c444e35095cb9ac46b4548e1eda8987-image.png)

### 代码

```python
class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        nums.sort()
        mid = (len(nums) + 1) / 2
        first = nums[:mid][::-1]
        second = nums[mid:][::-1]
        nums[::2], nums[1::2] = first, second
```

```python
import random

class Solution(object):
    def wiggleSort(self, nums):
        def partition(idx, start, stop):
            nums[idx], nums[stop] = nums[stop], nums[idx]
            pivot = nums[stop]
            idx = start
            for i in range(start, stop + 1):
                if nums[i] < pivot:
                    nums[idx], nums[i] = nums[i], nums[idx]
                    idx += 1

            nums[stop], nums[idx] = nums[idx], nums[stop]
            return idx

        def divide(start, stop):
            if stop <= start: return
            rand_idx = random.randint(start, stop)
            pivot = partition(rand_idx, start, stop)
            #print(nums, pivot, rand_idx)
            if pivot == mid:
                return
            elif pivot < mid:
                divide(pivot + 1, stop)
            else:
                divide(start, pivot - 1)

        mid = (len(nums)) / 2
        divide(0, len(nums) - 1)
        #print(mid, nums)

        def getRealIdx(i):
            return (1 + 2 * i) % (len(nums) | 1)

        mid_value = nums[mid]
        start, stop = 0, len(nums) - 1
        idx = 0
        while idx <= stop:
            if nums[getRealIdx(idx)] > mid_value:
                nums[getRealIdx(idx)], nums[getRealIdx(start)] = nums[getRealIdx(start)], nums[getRealIdx(idx)]
                idx += 1
                start += 1
            elif nums[getRealIdx(idx)] < mid_value:
                nums[getRealIdx(idx)], nums[getRealIdx(stop)] = nums[getRealIdx(stop)], nums[getRealIdx(idx)]
                stop -= 1
            else:
                idx += 1
```
