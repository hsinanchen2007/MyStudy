![image.png](https://pic.leetcode-cn.com/49c0174beb45d408ef19bd5f0245246f2c7f7cef651e63be2ded222a2bbfe2e3-image.png)

比较难的简单题，想又简洁又快并不太容易，给数组末尾添了两个数，就不用做边界判断。

简单题个人最难前五之一，剩下的非锁简单题就三道了。

```python
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        flag = True
        nums += [10000, 0]
        for i in range(len(nums) - 2):
            if nums[i] > nums[i + 1]:
                if not flag:
                    return False
                if nums[i + 1] < nums[i - 1]:
                    nums[i + 1] = nums[i]
                else:
                    nums[i] = nums[i - 1]
                flag = False
        return True
```
