### 解题思路
结合列表的index方法和bisect解决问题，注意index找不到是要抛异常的。

### 代码

```python3
import bisect

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        try:
            loc = nums.index(target)
            return loc
        except ValueError:
            return bisect.bisect_left(nums, target)

```