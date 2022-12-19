### 解题思路
始终让Counter里面只有两个元素

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        from collections import Counter
        count = Counter()
        for i in nums:
            # 直接统计词频
            count[i] += 1
            # 当count里面的元素达到三个时，则将每个元素的计数减去1
            if len(count) == 3:
                count -= Counter(set(count))
        # final check
        return [n for n in count if nums.count(n) > len(nums) / 3]
```