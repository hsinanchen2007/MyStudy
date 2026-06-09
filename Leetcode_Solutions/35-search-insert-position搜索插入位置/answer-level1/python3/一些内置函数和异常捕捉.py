### 解题思路
异常捕捉
### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        try:
            return nums.index(target)
        except ValueError:
            if target>nums[-1]:
                nums.append(target)
                return len(nums)-1
            for i in range(len(nums)):
                if nums[i]>target:
                    nums.insert(i,target)
                    return i
```