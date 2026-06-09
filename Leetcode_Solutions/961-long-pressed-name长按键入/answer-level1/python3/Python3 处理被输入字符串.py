### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        i=0
        j=0
        a=list(name)
        b=list(typed)
        while i<len(a) and j<len(b):
            if a[i]==b[j]:
                i+=1
                j+=1
            elif b[j]==b[j-1]:
                b.pop(j)
            else:
                return False
        if j<len(b):
            for x in range(j,len(b)):
                if b[x]!=b[x-1]:
                    return False
        elif i<len(a):
            return False
        return True
```