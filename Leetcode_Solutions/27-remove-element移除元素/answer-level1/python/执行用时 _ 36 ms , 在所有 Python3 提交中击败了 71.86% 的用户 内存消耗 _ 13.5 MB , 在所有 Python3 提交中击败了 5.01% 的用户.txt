### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i=0
        while i <len(nums):
            if nums[i]==val:
                nums.remove(nums[i])
            else:
                i+=1    
            

```