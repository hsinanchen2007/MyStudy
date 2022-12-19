## 思路
定义2个指针i=0,j=len(nums)-1
如果nums[i]是奇数,那么i指针向前,j指针固定。
如果nums[i]是偶数,那么i指针不动,直到nums[j]为偶数,交换俩个元素。
直到i>j
## 代码
```python
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        i, j = 0, len(nums) - 1
        while i < j:
            if nums[i] % 2 == 0:
                if nums[j] % 2 == 1:
                    nums[i], nums[j] = nums[j], nums[i]
                    i += 1
                j -= 1
            else:
                i += 1
        return nums
```
