### 解题思路
这个思路大家应该都能看懂

### 代码

```python3
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums: return 0  
        i=0
        while i+1!=len(nums):
            if nums[i]==nums[i+1]:
                nums.pop(i)
            else:
                i+=1
        return len(nums)
                
       
       

```