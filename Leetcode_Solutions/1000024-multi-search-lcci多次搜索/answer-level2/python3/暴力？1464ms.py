### 解题思路
枚举big所有子串，smalls构建字典，一个个干？

### 代码

```python3
class Solution:
    def multiSearch(self, big: str, smalls: List[str]) -> List[List[int]]:
        if not big or not smalls[0]:
            return [[]]*len(smalls)
        d = {i: [] for i in smalls}  # 全空格
        size = len(big)
        for i in range(size):
            for j in range(size):
                if big[i:j+1] in d:
                    d[big[i:j+1]].append(i)
        return list(d.values())
```