### 解题思路
暴力法：获取到最大的值，检查最大的值是不是其他值的两倍以上。

### 代码

```python3
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        if len(nums) < 2:
            return 0
        
        sortedNums = sorted(nums, reverse=True)
        print(sortedNums)
        for i in range(1, len(nums)):
            if sortedNums[0] < (sortedNums[i] * 2):
                return -1
        
        return nums.index(sortedNums[0])
```