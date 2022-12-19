### 解题思路
看代码很好理解

### 代码

```python3
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        from collections import Counter
        if len(s1)!=len(s2): return False 
        s1_map=Counter(s1)
        for c in s2:
            if c not in s1_map or s1_map[c]==0:
                return False
            s1_map[c]-=1
        return True

```