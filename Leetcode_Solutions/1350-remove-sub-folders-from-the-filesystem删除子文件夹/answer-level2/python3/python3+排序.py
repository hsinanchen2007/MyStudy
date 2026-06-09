### 解题思路
可以先排序，在逐个扫描

### 代码

```python3
class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        res, t = [], ' '
        for f in sorted(folder):
            if not f.startswith(t):
                res.append(f)
                t = f + '/'
        return res
```