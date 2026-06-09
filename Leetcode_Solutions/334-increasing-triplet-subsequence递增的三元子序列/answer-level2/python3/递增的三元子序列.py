### 解题思路
分治法？找到arr[j]，j之前的数字存在比arr[j]小的数字，j之后的数字存在比arr[j]大的数字，等价于arr[j]左边的最小值小于arr[j]，arr[j]右边最大的值大于arr[j]。但是效率比较低：
![image.png](https://pic.leetcode-cn.com/4118283297c7baaef1666d9940221576dca9bfb8f282d8db55f5a1360df76ba0-image.png)


### 代码

```python3
class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        if len(nums) < 3:
            return False
        for i in range(1, len(nums)-1):
            if nums[i] > (min(nums[:i])) and nums[i] < (max(nums[i+1:])):
                return True
        return False
```