### 解题思路
一次遍历
如果当前t元素等于s的头元素，就删掉s的头元素
如果遍历过程中或者最后s为空，返回True
否则返回False

### 代码

```python3
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        for i in range(len(t)):
            if not s:
                return True
            if t[i] == s[0]:
                s = s[1:]
        if not s: return True
        return False
```