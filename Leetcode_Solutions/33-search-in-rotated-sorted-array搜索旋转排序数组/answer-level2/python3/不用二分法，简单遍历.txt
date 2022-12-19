### 解题思路
此处撰写解题思路
作为小白，感觉二分法用着略微复杂，所以用得for循环遍历得出索引值。
### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        for i in range(len(nums)):
            if nums[i]==target:
                return i
        if target not in nums:
            return -1

```