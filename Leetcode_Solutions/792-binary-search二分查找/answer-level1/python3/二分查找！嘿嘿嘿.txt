### 解题思路
我终于会写二分查找啦！

![image.png](https://pic.leetcode-cn.com/4ade148e4ef4f5ee049c51a6ac68a3e6d97bd6c50c3f98f929e14047c8eec641-image.png)


### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums: return -1 # target = 0时not target = TRUE
        l, r = 0, len(nums) - 1
        while l <= r:
            m = (l + r) // 2
            if nums[m] == target: 
                return m
            elif nums[m] < target:
                l = m + 1
            else:
                r = m - 1
        return -1

```