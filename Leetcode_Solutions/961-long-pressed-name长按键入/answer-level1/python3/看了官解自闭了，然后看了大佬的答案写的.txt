### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        i, j = 0, 0
        for i in range(len(typed)):
            if j == len(name) - 1 and name[j] == typed[i]:
                return True
            if typed[i] == name[j]:
                j += 1
        return False
```