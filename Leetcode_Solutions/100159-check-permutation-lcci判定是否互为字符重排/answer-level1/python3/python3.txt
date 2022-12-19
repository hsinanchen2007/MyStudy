### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def CheckPermutation(self, s1: str, s2: str) -> bool:
        d = {}
        for i in s1:
            d[i]=d.get(i,0)+1
        for i in s2:
            if i not in d:
                return False
            d[i]-=1
            if d[i]<0:
                return False
        for i in d:
            if d[i]!=0:
                return False
        return True
```