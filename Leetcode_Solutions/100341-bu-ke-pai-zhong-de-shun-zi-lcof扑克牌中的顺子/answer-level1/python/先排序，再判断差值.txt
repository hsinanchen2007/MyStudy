### 解题思路
先排序，判断除0外是否有相同的元素，顺子中除0外的最大值与最小值之差必定不会大于4

### 代码

```python3
class Solution:
    def isStraight(self, nums: List[int]) -> bool:
        nums.sort()
        z = nums.count(0)
        for i in range(z, len(nums)-1):
                if nums[i+1] - nums[i] == 0:
                    return False
        if nums[-1] - nums[z] > 4:
            return False
        else:
            return True
```