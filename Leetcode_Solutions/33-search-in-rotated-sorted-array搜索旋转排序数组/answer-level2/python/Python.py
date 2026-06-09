### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def search(self, nums, target):
        l=0
        h=len(nums)-1
        while h>=l:
            m=l+(h-l)/2
            if nums[m]==target:
                return m
            if nums[l]<=nums[m]:
                if target>=nums[l] and target<nums[m]:
                    h=m
                else:
                    l=m+1
            else:
                if target>nums[m] and target<=nums[h]:
                    l=m+1
                else:
                    h=m
        return -1
```