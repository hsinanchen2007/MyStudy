执行用时52 ms, 在所有 Python3 提交中击败了75.53%的用户
内存消耗 :13.2 MB, 在所有 Python3 提交中击败了34.17%的用户

双指针，随便扫扫，没难度
```python []
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        j = 0
        for i in range(0, len(nums)):
            if nums[i] != val:
                nums[j] = nums[i]
                j += 1
        return j

```

