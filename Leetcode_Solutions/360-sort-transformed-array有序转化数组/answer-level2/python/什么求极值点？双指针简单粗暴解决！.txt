### 解题思路
a > 0的话，那从两边往中间，计算结果越来越小。取左右指针，比大小，依次从后往前填到结果即可。
a < 0的话，那从两边往中间，计算结果必然越来越大。同样取左右指针，比大小，依次从前往后填到结果中即可
a == 0, 随便塞到上面哪种情况下即可。

### 代码

```python
class Solution(object):
    def sortTransformedArray(self, nums, a, b, c):
        """
        :type nums: List[int]
        :type a: int
        :type b: int
        :type c: int
        :rtype: List[int]
        """
        result = [0] * len(nums)

        def calculate(x):
            return a * x ** 2 + b * x + c

        left, right = 0, len(nums) - 1
        if a > 0:
            point, offset = len(nums) - 1, -1
        else:
            point, offset = 0, 1

        left_val, right_val = calculate(nums[left]), calculate(nums[right])
        while left < right:
            if (a <= 0 and left_val < right_val) or (a > 0 and left_val > right_val):
                result[point] = left_val
                left += 1
                left_val = calculate(nums[left])
            else:
                result[point] = right_val
                right -= 1
                right_val = calculate(nums[right])
            point += offset

        result[point] = left_val
        return result
```