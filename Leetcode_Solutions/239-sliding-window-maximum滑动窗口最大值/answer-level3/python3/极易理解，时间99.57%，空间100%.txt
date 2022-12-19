### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums or k == 0:
            return []
        cur_max = max(nums[ : k])
        res = [cur_max]
        size = len(nums)
        for i in range(1, size - k + 1):
            # 如果最大值和移走的元素相等，那就重新计算。
            if nums[i - 1] == cur_max:
                cur_max = max(nums[i : i + k])
            # 不相表明最大值就在当前的区域中，只需和新加入的元素相比较。
            else:
                cur_max = max(cur_max, nums[i + k -1])
            res.append(cur_max)
        return res
```