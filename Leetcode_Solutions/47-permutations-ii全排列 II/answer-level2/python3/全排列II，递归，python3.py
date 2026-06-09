### 解题思路
一眼懂

### 代码

```python3
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        self.res = []
        self.method(nums,[])
        return self.res

    def method(self,nums,temp):
        if nums == []:
            self.res.append(temp)
            return
        for i in range(len(nums)):
            if i>0 and nums[i] == nums[i-1]:
                continue
            self.method(nums[:i]+nums[i+1:],temp+[nums[i]])
```