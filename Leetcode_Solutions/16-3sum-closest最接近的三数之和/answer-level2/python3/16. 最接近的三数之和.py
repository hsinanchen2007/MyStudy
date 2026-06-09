### 代码

```python3
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        if len(nums) < 3:
            return 
        # 先排序
        nums.sort()
        res = float('inf')
        for i in range(len(nums)):
            left = i + 1
            right = len(nums) - 1
            while left < right:
                summ = nums[i] + nums[left] + nums[right]
                if abs(summ - target) < abs(res - target):
                    res = summ
                # 如果三者之和是小于target的，左指针右移
                # 如果是大于target的，右指针左移
                # 如果恰好相等，则说明已经找到最接近的和数（==target），直接返回
                if summ < target:
                    left += 1
                elif summ > target:
                    right -= 1
                else:
                    return res
        return res
```