### 解题思路
若一个数组中，count(nums[i+1]-nums[i])>1,显然不可
若count=1，也可能存在false 比如[3,4,2,3],这种数组有一个特点就是nums[i]<nums[i-2]并且nums[i+1]<nums[i-1]

### 代码

```python
class Solution(object):
    def checkPossibility(self, nums):
        count = 0
        for i in range(1,len(nums)):
            if nums[i] < nums[i-1] :
                count += 1
                if count > 1:
                    return False
                if count == 1 and  2 <= i < len(nums)-1:
                    if nums[i] < nums[i-2] and nums[i+1] < nums[i-1]:
                        return False
        return True
```