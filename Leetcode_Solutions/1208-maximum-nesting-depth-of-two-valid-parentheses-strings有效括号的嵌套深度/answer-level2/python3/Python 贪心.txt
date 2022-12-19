
![image.png](https://pic.leetcode-cn.com/2c19bae1e78b8c055f63262717636349176a8fc97a441ed32ce2569e84dacc42-image.png)

```
'''
题目问题是要把字符分成两堆，让两堆的深度相差最小，如果出现()或者)(这样情况
两个连续的字符放到同一堆，不会让深度增加，其他情况两个字符需要分在不同两堆
这样总体可维护深度差最小，一种贪心策略
'''

from typing import List
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        ans = [0 for _ in range(len(seq))]
        for i in range(1, len(seq)):
            ans[i] = ans[i-1] if seq[i] != seq[i-1] else 1 - ans[i-1]
        return ans
```
