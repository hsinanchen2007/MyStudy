类快排的双指针,结果双百,代码如下:
```python
class Solution:
    def exchange(self, nums: List[int]) -> List[int]:
        #快速查找可以吗?
        if not nums:
            return []
        l,r = 0,len(nums)-1
        mid = nums[l]
        while l<r:
            while l<r and nums[r]%2==0:
                r-=1
            nums[l] = nums[r]
            while l<r and nums[l]%2 == 1:
                l+=1
            nums[r] = nums[l]
        nums[l] = mid
        return nums
```
![Screen Shot 2020-02-22 at 9.46.56 PM.png](https://pic.leetcode-cn.com/84813b3b54d56d7196aab1b902e1c85c7f11f56aab352847d06af13e3ed40700-Screen%20Shot%202020-02-22%20at%209.46.56%20PM.png)
