### 解题思路
1. 解题目标：每个元素的下一个最大，循环数组
2. 解题思路：
- 单调队列
- 先维护一个原数组的单调队列

### 代码

```python3
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        len_nums = len(nums)
        s = []
        res = []
        for i in range(len_nums-1,-1,-1):
            while s and s[-1] <= nums[i]:
                s.pop()
            s.append(nums[i])
        for i in range(len_nums-1,-1,-1):
            while s and s[-1] <= nums[i]:
                s.pop()
            if s:res.append(s[-1])
            else:res.append(-1)
            s.append(nums[i])
        res.reverse()
        return res
```