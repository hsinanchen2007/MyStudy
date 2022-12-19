### 解题思路
遇到1计数，遇到0 对比之前记录的最大连续数，最后返回计数与连续数中最大的那个

### 代码

```python3
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        i = 0
        count = 0
        ones = 0
        while i<len(nums):
            if nums[i] == 1:
                count += 1
            else:
                ones = max(ones,count)
                count = 0
            i += 1
        return max(ones,count)
```