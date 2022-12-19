### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def rob(self, nums: List[int]) -> int:
        n=len(nums)
        if n==0:
            return 0
        if n<=2:
            return max(nums)
        geld=[0]*n
        geld[0],geld[1]=nums[0],max(nums[0],nums[1])
        for i in range(2,n):
            geld[i]=max(geld[i-2]+nums[i],geld[i-1])
        return geld[-1]
```