### 解题思路
摩尔排序：
设基准数为数组第一个元素，此时出现次数为1， 遍历数组元素；
1. 如果当前元素等于基准数， 出现次数+1；
2. 如果当前元素不等于基准数， 出现次数-1；
3. 当出现次数等于0时，说明之前的已经全部抵消，没有找到次数最多的数，重新设置基准数为当前数。

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 1
        pivot = nums[0]
        for num in nums[1:]:
            if count == 0:
                pivot = num
                count = 1
            elif num == pivot:
                count += 1
            elif num != pivot:
                count -= 1
        return pivot
```