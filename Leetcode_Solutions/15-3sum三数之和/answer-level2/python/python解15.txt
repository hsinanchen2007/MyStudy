### 解题思路
1. 先对数组进行排列
2. 有三个指针，base，left和right。
3. base从0开始遍历到倒数第三个
4. left=base+1，right=最后一个元素
5. 如果-base > left + right 则left++
6. 如果-base < left + right 则right--

### 代码

```python
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        combinary = []
        nums.sort()
        if len(nums) < 3:
            return 
        base = 0
        while (base < len(nums) - 2 and nums[base] <= 0):
            left = base + 1
            right = len(nums) - 1
            while(left<right):
                if (-nums[base] == nums[left] + nums[right]):
                    combinary.append([nums[base], nums[left], nums[right]])
                    while ((left < right) and (nums[left] == nums[left+1])): left += 1
                    while ((left < right) and (nums[right] == nums[right-1])): right -= 1
                    left += 1
                    right -= 1
                elif (-nums[base] > nums[left] + nums[right]):
                    left += 1
                elif (-nums[base] < nums[left] + nums[right]):
                    right -= 1
            while (base<len(nums) - 2) and (nums[base] == nums[base+1]):  base += 1
            base += 1
        return combinary
                
                

            
                
            
            
        


        
        
        
```