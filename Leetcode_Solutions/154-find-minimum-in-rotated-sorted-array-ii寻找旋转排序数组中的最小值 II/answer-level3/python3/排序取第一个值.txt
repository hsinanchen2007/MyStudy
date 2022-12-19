### 解题思路
取排序之后的第一个值，需要额外空间

### 代码

```python
class Solution:
    def findMin(self, nums: List[int]) -> int:
        if not nums:
            return
        # 暴力法
        return sorted(nums)[0]

```