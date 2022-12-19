### 解题思路
快慢指针，和26删除重复项类似
由上题启发，可以对列表进行一次排序，以减少工作量。

### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        lens = len(nums)
        i = 0
        nums.sort()
        for j in range(lens):
            if nums[j] != val:
                if i != j:
                    nums[i], nums[j] = nums[j], nums[i]
                i += 1
        return i

```