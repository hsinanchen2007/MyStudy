### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s_map = collections.Counter(s)
        t_map = collections.Counter(t)
        return s_map == t_map

```