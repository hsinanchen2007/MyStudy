### 解题思路
分成三种情况，整体思路是二分查找

![image.png](https://pic.leetcode-cn.com/4dfbfa679c02bbd8a994b9d77cae503af3bc3bd26dc71a362af67f22cf5de340-image.png)

### 代码

```python
class Solution:
    def findMin(self, nums: List[int]) -> int:
        if not nums:
            return
        l, r = 0, len(nums) - 1

        while l < r:
            m = (l+r) // 2
            if nums[l] < nums[r]:
                return nums[l]
            elif nums[l] > nums[r]:
                if nums[m] <= nums[r]:
                    r = m
                else:
                    l = m+1
            elif nums[l] == nums[r]:
                l += 1
        return nums[l]


```