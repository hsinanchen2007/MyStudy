### 解题思路
set()去重，在统计sum()

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        half = len(nums) // 2
        count = set(nums)
        for num in count:
            count1 = sum(1 for i in nums if i == num)
            if count1 > half:
                return num

```