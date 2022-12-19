### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def countSteppingNumbers(self, low, high):
        """
        :type low: int
        :type high: int
        :rtype: List[int]
        """
        def bs(array, target):
            start, stop = 0, len(array)
            while start < stop:
                mid = (start + stop) / 2
                if array[mid] >= target:
                    stop = mid
                else:
                    start = mid + 1
            return start

        def bt(nums, result):
            next_nums = []
            for num in nums:
                for j in [-1, 1]:
                    if (num % 10 == 9 and j == 1) or (num % 10 == 0 and j == -1): continue
                    num = num * 10 + num % 10 + j
                    next_nums.append(num)
                    num /= 10
            start, stop = bs(next_nums, low), bs(next_nums, high)
            if stop < len(next_nums) and next_nums[stop] == high:
                stop += 1
            result += next_nums[start:stop]
            if next_nums[-1] <= high:
                result = bt(next_nums, result)
            return result

        result = range(low, min(high, 9) + 1)
        return bt(range(1, 10), result)
```