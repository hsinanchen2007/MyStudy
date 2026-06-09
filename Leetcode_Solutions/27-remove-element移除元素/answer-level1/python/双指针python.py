解法一：双指针，只覆盖val

```python
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        n = len(nums)
        end = n-1
        start = 0
        if n == 0:
            return 0        
        while start < end:
            while start < end and nums[start] != val:
                start = start + 1
            while start < end and nums[end] == val:
                end = end -1
            nums[start],nums[end] = nums[end],nums[start]
            start = start + 1
            end = end - 1
        for i in range(n):
            if nums[i] == val:
                return i
```






解法二：全覆盖

```python
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        start = 0
        for i in range(len(nums)):
            if nums[i] == val:
                continue
            else:
                nums[start] = nums[i]
                start = start + 1
        return start
```


