### 解题思路

### 代码

```python3
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        ans = list(t)
        for i in s:
            ans.remove(i)
        return ans[0]
```