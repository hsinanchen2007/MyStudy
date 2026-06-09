### 解题思路
1. idx 按照步长为2，从0开始递增，nums[idx]为频率，nums[idx+1]为应该出现的数字。

### 代码

```python3
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        uncomp = []
        for idx in range(0, len(nums)-1, 2):
            uncomp += nums[idx]*[nums[idx+1]]
        return uncomp
```