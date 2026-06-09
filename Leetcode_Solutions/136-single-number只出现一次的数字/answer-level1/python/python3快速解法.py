### 解题思路
用到列表自带排序sort()
时间快、内存消耗少

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums.sort()
        if len(nums)==1:
            return nums[0]
        if nums[0]==nums[1]:
            for i in range(2,len(nums)-2,2):
                if nums[i]!=nums[i+1]:
                    return nums[i]
                
        else:
            return nums[0]
        return nums[len(nums)-1]
```