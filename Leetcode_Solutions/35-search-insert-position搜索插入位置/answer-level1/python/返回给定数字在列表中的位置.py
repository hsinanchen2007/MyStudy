### 解题思路
这个简单而言是一个计数的问题，在解题过程中，要注意当给定数字不在列表中的情况，

### 代码

```python3
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        i=0
        if target in nums:
            for item in nums:
                if item==target:
                    return i
                else:
                    i+=1
        else:
            for it in nums:
                if it< target:
            
                    i+=1
                    if i==len(nums):
                        return len(nums)

                else:
                    return i
                    break

                    
                
            
```