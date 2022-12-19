### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def isValid(self, s: str) -> bool:
        if not s:
            return True
        l = ['0']      #哨兵
        for i in s:
            if i in ['(','[','{']:
                l.append(i)
            elif l[-1]+i not in ['{}','()','[]'] :
                return False
            else :
                l.pop()
        return len(l) == 1
```