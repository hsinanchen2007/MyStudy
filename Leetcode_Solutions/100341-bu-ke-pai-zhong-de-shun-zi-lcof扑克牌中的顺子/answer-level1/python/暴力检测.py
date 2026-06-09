### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def isStraight(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        nums.sort()
        if nums[3]==0:
            return True
        elif nums[2]==0:
            if nums[3]!=nums[4] and nums[4]-nums[3]<=4:
                return True
            else:
                return False
        elif nums[1]==0:
            if nums[2]+1 == nums[3] and nums[3]+1==nums[4]:
                return True
            elif nums[2]+3 == nums[3] and nums[3]+1==nums[4]:
                return True
            elif nums[2]+2 == nums[3] and nums[3]+2==nums[4]:
                return True
            elif nums[2]+1 == nums[3] and nums[3]+3 == nums[4]:
                return True
            elif nums[2]+1==nums[3] and nums[3] +2 == nums[4]:
                return True
            elif nums[2]+2==nums[3] and nums[3] + 1==nums[4]:
                return True
            else:
                return False
        elif nums[0]==0:
            if nums[1]+1 == nums[2] and nums[2]+1 == nums[3] and nums[3]+1==nums[4]:
                return True
            elif nums[1]+1 == nums[2] and nums[2]+1 == nums[3] and nums[3]+2==nums[4]:
                return True
            elif nums[1]+1 == nums[2] and nums[2]+2 == nums[3] and nums[3]+1==nums[4]:
                return True
            elif nums[1]+2 == nums[2] and nums[2]+1 == nums[3] and nums[3]+1==nums[4]:
                return True
            else:
                return False
        else:
            if nums[0]+1==nums[1] and nums[1]+1==nums[2] and nums[2]+1==nums[3] and nums[3]+1==nums[4]:
                return True
            else:
                return False
```