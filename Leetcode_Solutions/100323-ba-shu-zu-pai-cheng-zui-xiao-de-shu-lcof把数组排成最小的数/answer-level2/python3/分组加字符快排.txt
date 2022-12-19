### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    # def minNumber(self, nums: List[int]) -> str:
    def minNumber(self, nums):
        if not nums:
            return ''
        num_group = [[] for _ in range(10)]
        nums = list(map(str, nums))
        re = ''
        for i in nums:
            num_group[int(i[0])] += [i]
        def quicksort(arr):
            if not arr:
                return arr
            mid = arr[0]
            l = []
            r = []
            for i in arr[1:]:
                if mid + i > i + mid:
                    l += [i]
                else:
                    r += [i]
            return quicksort(l) + [mid] + quicksort(r)
        for i in range(10):
            if num_group[i]:
                re += ''.join(quicksort(num_group[i]))
        return re


```