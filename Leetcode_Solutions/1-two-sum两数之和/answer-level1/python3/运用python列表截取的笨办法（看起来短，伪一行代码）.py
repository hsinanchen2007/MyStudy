### 解题思路
先遍历，当前值为x,在x位置到结尾搜索target - x，找到就可以直接返回x和target-x在x之后的索引。

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for _ in nums:
            if target - _ in nums[nums.index(_)+1:]:
                return [nums.index(_),nums.index(target - _,nums.index(_)+1)]

```