### 解题思路
    方法: 排序 + 双指针
    前提: 保证数组有序, 则可通过指针移动的方向来控制总值是变大还是变小
    过程: 固定一个数, (假设数组单调不减)若总值偏大, 则右指针左移, 若总值偏小,
        则左指针右移, 直到总值等于target, 或者左右指针无法继续移动

### 代码

```python3
class Solution:
    """
    方法: 排序 + 双指针
    前提: 保证数组有序, 则可通过指针移动的方向来控制总值是变大还是变小;
    过程: 固定一个数, (假设数组单调递增)若总值偏大, 则右指针左移, 若总值偏小,
    则左指针右移, 直到总值等于target, 或者左右指针无法继续移动
    """
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        length = len(nums)
        min_diff = 2 ** 32 - 1
        for i in range(0, length - 2):
            j = i + 1
            k = length - 1
            while j < k:
                value = nums[i] + nums[j] + nums[k]
                diff = abs(target - value)
                if diff == 0:
                    return value
                if diff < min_diff:
                    min_diff = diff
                    ret = value
                if value > target:
                    k -= 1
                else:
                    j += 1
        return ret
```