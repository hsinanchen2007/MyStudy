### 解题思路
空间复杂度可降至O(1)

### 代码

```python3
class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        i=0
        j=0
        while i < len(name) and j < len(typed):
            if name[i]==typed[j]:
                i+=1
                j+=1
            else:
                if typed[j]!=typed[j-1]:
                    return False
                j+=1
        if i < len(name):
            return False
        for r in range(j,len(typed)):
            if typed[r]!=name[-1]:
                return False
        return True
```