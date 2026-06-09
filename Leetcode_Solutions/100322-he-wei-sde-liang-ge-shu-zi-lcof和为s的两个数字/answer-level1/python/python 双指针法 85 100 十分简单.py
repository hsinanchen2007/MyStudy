### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        l=0
        r= len(nums)-1
        while l<r:
            if (nums[l]+nums[r])<target:
                l+=1
            elif (nums[l]+nums[r])>target:
                r-=1
            else :
                return[nums[l],nums[r]]
```