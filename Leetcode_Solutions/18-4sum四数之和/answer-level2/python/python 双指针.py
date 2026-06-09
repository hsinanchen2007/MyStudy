### 解题思路
执行用时 :840 ms, 在所有 Python 提交中击败了21.94%的用户
内存消耗 :11.7 MB, 在所有 Python 提交中击败了85.85%的用户

结果一般，在三数之和的基础上改的
双层循环嵌套，增加判断条件[if j==i+1 or nums[j]>nums[j-1]:]

### 代码

```python
class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        keys =[]
        for i in range(len(nums)-1):
            if i == 0 or nums[i]>nums[i-1]:
                for j in range(i+1,len(nums)):
                    if j==i+1 or nums[j]>nums[j-1]:
                        left = j+1
                        right = len(nums)-1
                        while left < right:
                            sum = nums[i] + nums[j] + nums[left] +nums[right]
                            if sum == target:
                                keys.append([nums[i],nums[j],nums[left],nums[right]])
                                left +=1
                                right -=1
                                while left < right and nums[left] == nums[left-1]:
                                    left += 1
                                while right > left and nums[right] == nums[right+1]:
                                    right -= 1
                            elif sum > target:
                                right -=1
                            else :
                                left +=1
        return keys
```