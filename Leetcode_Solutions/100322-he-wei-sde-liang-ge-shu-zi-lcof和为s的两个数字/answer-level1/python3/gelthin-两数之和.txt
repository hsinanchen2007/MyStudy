### 解题思路
双指针

同主站习题 [167. 两数之和 II - 输入有序数组](https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/)

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        i, j = 0, len(nums)-1
        while i < j:
            if nums[i] + nums[j] == target:
                return [nums[i], nums[j]]
            elif nums[i]+nums[j] < target:
                i += 1
            else:
                j -= 1
        # 如果没找到 或者 nums 长度为 1
        return []
```