### 解题思路
快速排序的思路

### 代码

```python3
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        p = 0
        q = len(nums)-1
        while(p<=q):
            while(p<=q and nums[p] % 2 == 1): p += 1
            while(p<=q and nums[q] % 2 == 0): q -= 1
            if p <= q:
                nums[p], nums[q] = nums[q], nums[p]
                p += 1
                q -= 1
        return nums

```