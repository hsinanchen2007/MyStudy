### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        if sorted(s1) == sorted(s2):
            return True
        else:
            return False
```