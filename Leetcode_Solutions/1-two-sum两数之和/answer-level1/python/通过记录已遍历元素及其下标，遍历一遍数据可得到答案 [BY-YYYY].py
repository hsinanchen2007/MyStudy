### 解题思路
> 尝试暴力法求解，直接超过时间限制。开始重新思考做法，因题目中已指明每种输入只会对应一个答案，可认为数组中的元素是不重复的，在遍历时，可用dict将元素值及下标记录下来，这样可以查找target-curNum是否已经在dict中来得到答案，遍历一遍数组即可，时间复杂度为O(n).

### 代码

```python3
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        has = {}
        for i in range(0, len(nums)):
            if target - nums[i] in has:
                return [has[target - nums[i]], i]
            has[nums[i]] = i
        return []
```