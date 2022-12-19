### 解题思路
-   因为数组是非递减的，因此可以使用二分查找
-   通过二分查找找出元素的数量，然后判断是否大于数组长度的一半




### 代码

```python
import bisect


class Solution:
    def isMajorityElement(self, nums: List[int], target: int) -> bool:
        half = len(nums) // 2 + 1

        return (bisect.bisect_right(nums, target) - bisect.bisect_left(nums, target)) >= half

```
