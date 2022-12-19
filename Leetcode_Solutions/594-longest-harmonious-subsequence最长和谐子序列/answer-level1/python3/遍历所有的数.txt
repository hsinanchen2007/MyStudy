### 解题思路
此处撰写解题思路

### 代码

```python3
from collections import Counter

class Solution:
    def findLHS(self, nums: List[int]) -> int:
        count = Counter(nums)
        # 只有一种数的情况
        if not (len(count.keys()) -1 ):return 0
        max_len = 0
        # 遍历
        for i in count.keys():
            if i-1 in count.keys() and count[i] + count[i - 1] > max_len:
                max_len = count[i] + count[i - 1]
        return max_len
```