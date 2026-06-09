### 解题思路
将一个固定，剩下两个作为指针，然后循环判断

### 代码

```python3
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        l = len(nums)
        if not nums or l < 3:
            return []
        nums.sort() # python的sort用的是timesort算法，具体如下
        # https://www.cnblogs.com/clement-jiao/p/9243066.html
        res = []
        for i in range(l):
            if nums[i] > 0:
                return res
            if i > 0 and nums[i] == nums[i-1]:
                continue # 跳出本次循环
            left = i + 1
            right = l - 1
            while left < right:
                if nums[i] + nums[left] + nums[right] < 0:
                    left += 1
                elif nums[i] + nums[left] + nums[right] > 0:
                    right -= 1
                else:
                    res.append([nums[i],nums[left],nums[right]])
                    while left < right and nums[left] == nums[left+1]: # 这里跟下面的边界比较是用来防止越界的，所以不能省！！！
                        left+=1
                    while left < right and nums[right] == nums[right-1]:
                        right-=1
                    left+=1
                    right-=1
        return res

```