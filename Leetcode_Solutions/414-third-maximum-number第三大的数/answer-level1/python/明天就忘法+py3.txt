### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        first, second, thirth = float('-inf'), float('-inf'), float('-inf')
        # 先去重
        nums = list(set(nums))
        for num in nums:
            # 如果进来的元素 大于第一大的数 则更新第1 2 3 大的数
            if num > first:
                thirth = second
                second = first
                first = num
            # 如果进来的元素不大于第一大的数 但是大于第二大的数
            # 则更新第二大的数和第三大的数
            elif num > second:
                thirth = second
                second = num
            # 如果进来的数 只大于第三大的数 则只更新第3大的数
            elif num > thirth:
                thirth = num
        # 如果没有第三大的数 则返回第一大的数
        return first if thirth == float('-inf') else thirth