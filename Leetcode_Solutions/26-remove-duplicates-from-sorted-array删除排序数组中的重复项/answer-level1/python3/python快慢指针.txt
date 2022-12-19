### 解题思路
看了大佬的讲解快慢指针，貌似python是这样实现的。

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        i = 0
        for j in range(len(nums)):
            if nums[j] == nums[i]:
                continue
            else:
                nums[i+1] = nums[j]
                i += 1
        return i+1

```