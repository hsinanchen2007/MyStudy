### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        n = len(nums)
        nums.append(n+2)
        print(n)
        for num in nums:
            index = abs(num)
            print(index)
            if index == (n+2):
                break        
            if num == -(n+3):
                nums[0] = -abs(nums[0])
            elif nums[index] == 0:
                nums[index] = -(n+3)        
            else:
                nums[index] = -abs(nums[index])
        print(nums)
        for i in range(len(nums)):
            if nums[i] >= 0:
                return i

            
        

        














```