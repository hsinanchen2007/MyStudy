### 解题思路
遍历每个数，如果目标值减去当前值的差在后面的列表中，则跳出循环，返回索引值

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i,x in enumerate(nums):
            if target-x in nums[i+1:]:
                break
        return [i,nums[i+1:].index(target-x)+i+1]
               
                
```