标准动态规划，要看能不呢和前一位凑到小于25，一定要注意小于10不能再算凑一次
```python
class Solution:
    def translateNum(self, num: int) -> int:
        if num < 10:
            return 1
        nums = [int(i) for i in str(num)]
        result = [1 for i in range(len(nums) + 1)]
        for i in range(2, len(nums)+1):
            if nums[i-2] == 1 or (nums[i-2] == 2 and nums[i-1] <= 5):
                result[i] = result[i-1] + result[i-2] 
            else:
                result[i] = result[i-1] 
        return result[-1]
```
