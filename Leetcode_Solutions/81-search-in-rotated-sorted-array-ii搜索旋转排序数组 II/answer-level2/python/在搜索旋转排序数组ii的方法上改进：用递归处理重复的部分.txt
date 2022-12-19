### 解题思路
用递归应该会比遍历好一些吧hmmm

### 代码

```python
class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        if not nums:
            return False
        left, right = 0, len(nums)-1
        while left<=right:
            mid = (left+right)//2
            if nums[mid] == target:
                return True
            # 右边有序
            if nums[mid]<nums[right]:
                
                if nums[mid]<target<=nums[right]:
                    left = mid+1
                else:
                    right = mid-1
            elif nums[mid] == nums[right]:
                return self.search(nums[:mid], target) or self.search(nums[(mid+1):], target)
            # 左边有序
            else:
                if nums[left]<=target<nums[mid]:
                    right = mid-1
                else:
                    left = mid+1
        return False

```
