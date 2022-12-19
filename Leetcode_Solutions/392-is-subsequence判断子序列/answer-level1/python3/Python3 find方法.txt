### 解题思路
一看就懂

### 代码

```python3
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        tmp = -1
        for i in s:
            tmp = t.find(i,tmp+1)
            if tmp == -1:
                return False
        return True
```