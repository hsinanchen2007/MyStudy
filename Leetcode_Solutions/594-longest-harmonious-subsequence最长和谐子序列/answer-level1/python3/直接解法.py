
### 代码

```python3
from collections import Counter

class Solution:
    def findLHS(self, nums: List[int]) -> int:
        
        # 想用collections.Counter统计， 再计算cnt[k] + cnt[k+1] 这就是一个和谐子序列的长度
        cnt = Counter(nums)
        max_length = 0
        
        for k, v in cnt.items():
            if k+1 in cnt:
                length = v + cnt[k+1]
                max_length = max(max_length, length)
        
        return max_length
```