### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n=len(nums)
        if not nums or n<0 :
            return 
        for num in nums:
            if num<0 or num>n:
                return
        for i in range(n):
            # nums[i]要小于数组的长度 不小的话出现数组越界问题
            while nums[i]!=i and nums[i]<n:
                # 交换位置,把nums[i]放到这个值的对应的下标
                # 比如 [1,0],nums[0]=1, 那么把1放到 对应1 的下标
                nums[nums[i]],nums[i]=nums[i],nums[nums[i]]
        for i in range(n):
            if i!=nums[i]:
                return i
        return n

                  
        
```