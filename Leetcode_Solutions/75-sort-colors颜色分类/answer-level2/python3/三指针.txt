### 解题思路
根据官方文档写的
![image.png](https://pic.leetcode-cn.com/4596d6277b07bffa20abf133e882a667f03cfc6bdb9395735b02b3585d6191e4-image.png)

### 代码

```python3
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        p0, p2, c = 0, n-1 ,0
        while c <= p2:
            if nums[c] == 2:
                nums[c], nums[p2] = nums[p2], nums[c]
                p2 -= 1
            elif nums[c] == 0:
                nums[c], nums[p0] = nums[p0], nums[c]
                c += 1
                p0 += 1
            elif nums[c] == 1:
                c += 1
        return nums

```