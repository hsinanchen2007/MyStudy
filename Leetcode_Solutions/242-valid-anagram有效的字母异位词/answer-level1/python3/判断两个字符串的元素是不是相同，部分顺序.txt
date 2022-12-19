### 解题思路
时间复杂度：O（n）
空间复杂度：O（n）

### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        from collections import defaultdict
        d1 = defaultdict(int)
        d2 = defaultdict(int)
        for i in s:
            d1[i] += 1
        for i in t:
            d2[i] += 1
        return d1 == d2

```