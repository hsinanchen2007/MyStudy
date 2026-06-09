### 解题思路
时间复杂度小于O（n*n），有用到切片，如果能把切片改成索引的话应该能更快一点。

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        list = [1,2] 
        for i in range(len(nums)-1):
            if (target - nums[i]) in nums[i+1:] :
                list[0] = i
                list[1] = nums[i+1:].index(target - nums[i]) + i +1
        

        return list
```