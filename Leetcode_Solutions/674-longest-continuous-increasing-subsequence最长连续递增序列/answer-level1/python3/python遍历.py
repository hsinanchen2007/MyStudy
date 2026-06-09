直接一次遍历搞定
![微信截图_20191110214952.png](https://pic.leetcode-cn.com/3461b2d8c7e5c8091dadd8279210110c4b490133b61b58d36fa362c168b211d6-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20191110214952.png)
```
class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        n = len(nums)
        l = []
        count = 1
        for i in range(1, n):
            if nums[i] > nums[i - 1]:
                count += 1
            else:
                l.append(count)
                count = 1
            l.append(count)
        if not l:
            return len(nums)
        return max(l)
```


