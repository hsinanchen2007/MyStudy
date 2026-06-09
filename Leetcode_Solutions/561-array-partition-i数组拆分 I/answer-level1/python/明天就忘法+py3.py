### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
   
        if not nums:
            return 0
        nums.sort()
        res=0
        for i in range(len(nums)):
            # 下标为偶数
            if i&1==0:
               res+=nums[i]
        return res
```