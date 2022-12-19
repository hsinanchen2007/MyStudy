### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        ans = ""
        for i, j in itertools.groupby(S):
            ans += str(i) + str(len(list(j)))
        if len(ans) < len(S):
            return ans 
        else:
            return S
```