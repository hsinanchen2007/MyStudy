### 解题思路
官方题解方法三双指针法的Python版本

### 代码

```python3
class Solution:
    def threeSumSmaller(self, nums: List[int], target: int) -> int:
        if len(nums) < 3:  # 处理边界条件
            return 0
        nums.sort()
        ans = 0
        for i in range(len(nums) - 2):  # 注意i,j,k三个指针不能重合
            left = i + 1
            right = len(nums) - 1
            while left < right:
                # 如果left和right之和小于target-nums[i]，left右移
                if nums[left] + nums[right] < target - nums[i]:
                    ans += right - left
                    left += 1 
                # 如果left和right之和大于target-nums[i]，right左移
                else:
                    right -= 1
        return ans
```
### 复杂度分析
- 时间复杂度：$O(n^2)$。在每一步中，要么`left`向右移动一位，要么`right`向左移动一位。当`left = right`时循环结束，因此它的时间复杂度为$O(n)$。加上外层的循环，总的时间复杂度为$O(n^2)$。
- 空间复杂度：$O(1)$。

