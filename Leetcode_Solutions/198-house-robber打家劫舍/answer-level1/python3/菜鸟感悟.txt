### 解题思路
考虑一下list的长度小于2的情况，大于等于三就用动态规划

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        l=len(nums)
        if l==0:
            return 0
        elif l<2:
            return nums[0]
        elif l<3:
            return max(nums[0],nums[1])
        else:
            nums[1]=max(nums[0],nums[1])
        n=2
        while n<l:
            nums[n]=max(nums[n-1],nums[n]+nums[n-2])
            n=n+1
        return nums[l-1]




```