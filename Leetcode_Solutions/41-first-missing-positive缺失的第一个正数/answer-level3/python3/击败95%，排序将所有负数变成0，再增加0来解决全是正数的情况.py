### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        nums.append(0)
        nums.append(0)
        
        for i in range(0,len(nums)-1):
            if nums[i] < 0:
                nums[i] = 0
                

        nums.sort()
        print(nums)
        j = 0
        for i in range(1,len(nums)):
            if nums[i] - nums[i-1] > 1:
                return nums[i-1] + 1
            j+=1
        return nums[j] + 1

```