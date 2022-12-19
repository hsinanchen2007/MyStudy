### 解题思路
列表排序后，返回max(最后3位的乘积，前2位和最后一位的乘积)

### 代码

```python3
class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        nums=sorted(nums)
        return max(nums[-1]*nums[-2]*nums[-3],nums[0]*nums[1]*nums[-1])
```