### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        '''
        for i in range(1,len(nums)):
            if nums[i] and nums[i-1]:
                nums[i] = nums[i]+nums[i-1]
            else:
                nums[i]
        return max(nums)
        '''
        '''
        return len(max("".join([str(i) for i in nums]).split("0"),key=len))
        '''
        j = 0
        temp = 0
        for i in range(len(nums)):
            if nums[i]==1:
                j+=1
            else:
                temp = max(temp,j)
                j = 0
        return max(temp,j)

```