### 解题思路
调用Collections.Counter()方法

### 代码

```python3
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        from collections import Counter
        return [num[0] for num in Counter(nums).most_common(k) ]
```