### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if sorted(s) == sorted(t):
            return True
        else:
            return False


```