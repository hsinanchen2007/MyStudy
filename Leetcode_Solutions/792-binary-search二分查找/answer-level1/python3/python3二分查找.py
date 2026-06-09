```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left=0
        right=len(nums)-1
        while right>=left:
            mid=left+(right-left)//2
            if nums[mid]>target:
                right=mid-1
            elif nums[mid]==target:
                return mid
            else:
                left=mid+1
        return -1
```

![image.png](https://pic.leetcode-cn.com/3c276b867d574a2f9abe21e4943ba0cb89715a93e1f85e73ff75e7ba11064c63-image.png)

