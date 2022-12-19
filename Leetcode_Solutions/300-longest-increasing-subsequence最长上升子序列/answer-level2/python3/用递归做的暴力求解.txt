### 解题思路
做了我半天
用递归做的暴力求解 O(n^2)
以后再想O(nlogn)吧
### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        size = len(nums)
        if size <= 1:
            return size
        elif size == 2:
            return (2 if nums[0]<nums[1] else 1)
        else:
            i, max_size =0, 1
            while i <= size -2:
                if i >= 1 and nums[i]>nums[i-1]:
                    i +=  1
                else:
                    k = 1
                    j = self.OthMaxNum(i, nums)
                    if len(j)!= 0:
                        k = k+ self.lengthOfLIS(j)
                    if k> max_size:
                        max_size = k
                i += 1
            return max_size
    def OthMaxNum(self, pos, nums):
        tmp = []
        for i in range(pos+1, len(nums)):
            if nums[i]> nums[pos]:
                tmp.append(nums[i])
        return tmp





        
```