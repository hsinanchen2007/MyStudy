### 解题思路


### 代码

```python3
class Solution:
      def moveZeroes(self, nums: List[int]) -> None:    
        flag=-1
        for i in range(len(nums)):
            if nums[i]!=0:
                nums[flag+1],nums[i]=nums[i],nums[flag+1]
                flag+=1     
        return nums
 




```