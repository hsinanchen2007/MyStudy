### 解题思路
滑动窗口，重点理解maxcount，看注解

### 代码

```python3
from collections import defaultdict
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        # 滑动窗口
        if s is None or len(s) == 0:
            return 0
        hash = defaultdict(int)
        n = len(s)
        left = 0
        maxCount = 0
        res = 0
        for right in range(n):
            hash[s[right]] += 1
            # 当前窗口中元素最多的字符的数量
            maxCount = max(maxCount, hash[s[right]])
            # 注意这里为什么是while循环，举个特列 AABCD K=1,左指针必须移动到条件r-l+1不大于K
            while right - left + 1 - maxCount > k:
                hash[s[left]] -= 1
                left += 1
                # 这里按理也需要判断一下maxCount,为什么不判断了呢，相当于maxCount只大不小？
                # 这是由于我们只找满足条件的最大值，当大于maxcount的值出现，表示right-left+1的值更大!
            res = max(right - left + 1, res)
        return res
```