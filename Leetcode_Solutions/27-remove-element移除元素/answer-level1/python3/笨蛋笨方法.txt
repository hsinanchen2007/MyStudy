### 解题思路
直接拿列表中的每一个数字和给定值作比较，有则删除该值继续比较，没有则比较位+1

### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        while i <= len(nums) -1:
            if nums[i] == val:
                del nums[i]
            else:
                i += 1
        return len(nums)

```