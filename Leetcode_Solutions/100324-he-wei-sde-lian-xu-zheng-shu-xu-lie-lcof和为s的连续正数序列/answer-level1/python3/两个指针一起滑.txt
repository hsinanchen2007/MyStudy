设置两个指针i, j分别代表左边界和右边界，从i累加到j
当前的和为cur_sum
- 如果cur_sum大于target, i+1
- 如果cur_sum小于target, j+1
- 如果等于，添加到结果集中

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        i = j = 1
        res = []
        cur_sum = 0
        while j < target:
            cur_sum += j
            j += 1
            while cur_sum > target:
                cur_sum -= i
                i += 1
            if cur_sum == target:
                res.append(list(range(i, j)))
        return res
```