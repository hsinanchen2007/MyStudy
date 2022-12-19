![image.png](https://pic.leetcode-cn.com/e70e1fc131d2595f1ccfa74e5660d8b7a5ec10714d925ef0addab4dcab625363-image.png)

```python
class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if nums == [] or len(nums) < 3: return []
        nums.sort()
        
        res = []
        n = len(nums)
        for i in range(n):
            if nums[i] > 0: return res
            if i > 0 and nums[i] == nums[i - 1]: continue # 此处必须要i>0，否则会遗漏[0,0,0]
            l = i + 1
            r = n - 1
            while l < r:
                if nums[i] + nums[l] + nums[r] == 0:
                    res.append([nums[i], nums[l], nums[r]])
                    while l < r and nums[l] == nums[l + 1]: # 两个while必须放在这个if里，否则会遗漏如[-2,1,1]这种包含相同元素的
                        l += 1
                    while l < r and nums[r] == nums[r - 1]:
                        r -= 1
                    l += 1
                    r -= 1
                elif nums[i] + nums[l] + nums[r] < 0:
                    l += 1
                elif nums[i] + nums[l] + nums[r] > 0:
                    r -= 1
        return res
```