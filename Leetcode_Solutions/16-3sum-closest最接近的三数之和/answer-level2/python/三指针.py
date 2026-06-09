### 解题思路
1. 固定一个指针base
2. 确定俩个指针，一个left是base+1，一个right是最后一个元素
3. 遍历`base+left+right=sum`，如果`sum>target`,则right--。如果是`sum<target`，则left++。
4. 如果是`sum==target`，则返回当前的sum

### 代码

```python
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        min = 0
        if len(nums) < 3: return
        nums.sort() 
        base = 0
        min = nums[base] + nums[base+1] + nums[base+2]
        while (base < len(nums) - 2) :
            left = base + 1
            right = len(nums) - 1
            while (left<right):
                if abs(nums[base]+nums[left]+nums[right]-target) < abs(min - target):
                    min = nums[base] + nums[left] + nums[right]
                if nums[base] + nums[left] + nums[right] < target:
                    left += 1
                elif nums[base] + nums[left] + nums[right] > target:
                    right -= 1
                elif nums[base] + nums[left] + nums[right] == target:
                    return nums[base] + nums[left] + nums[right]
            base += 1
        return min
```