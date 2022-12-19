### 解题思路
> 单次遍历，标记最大值是否是上一次最大值的2倍

### 代码

```python3
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        if not nums:
            return -1
        biggest = nums[0]
        moreThanTwice = True
        index = 0
        for i in range(1, len(nums)):
            if nums[i] > biggest:
                if nums[i] >= biggest * 2:
                    moreThanTwice = True
                else:
                    moreThanTwice = False
                biggest = nums[i]
                index = i
            else:
                if biggest < nums[i] * 2:
                    moreThanTwice = False
        if moreThanTwice:
            return index
        return -1
```

# Time
```
执行用时 :44 ms, 在所有 Python3 提交中击败了54.07%的用户
内存消耗 :13.7 MB, 在所有 Python3 提交中击败了5.42%的用户
```