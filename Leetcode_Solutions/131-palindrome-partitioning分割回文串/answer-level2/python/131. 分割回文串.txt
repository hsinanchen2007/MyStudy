### 解题思路
- 将字符串递归的分割成回文串；

### 代码

```python3
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        res = []
        def solve(s, tmp):
            if not s:
                res.append(tmp)
                return 
            for i in range(1, len(s) + 1):
                if s[:i] == s[:i][::-1]:
                    solve(s[i:], tmp + [s[:i]])
        solve(s, [])
        return res
```