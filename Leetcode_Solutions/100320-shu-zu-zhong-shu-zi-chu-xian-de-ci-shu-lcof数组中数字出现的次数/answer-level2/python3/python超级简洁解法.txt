### 解题思路


### 代码

```python3
class Solution:
    def singleNumbers(self, nums: List[int]) -> List[int]:
        x=nums[0]
        for i in range(1,len(nums)):
            x^=nums[i]
        z=0
        c=0
        y=x&(-x)
        for i in range(len(nums)):
            if(nums[i]&y==y):
                z^=nums[i]
            else:
                c^=nums[i]
        return z,c
```