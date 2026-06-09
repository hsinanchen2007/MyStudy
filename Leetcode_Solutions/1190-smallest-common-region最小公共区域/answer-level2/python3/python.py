### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findSmallestRegion(self, regions: List[List[str]], region1: str, region2: str) -> str:
        q, p = set(), {i: j for j, *r in regions for i in r}
        while region1 in p:
            q.add(region1)
            region1 = p[region1]
        while region2 in p:
            if region2 in q: return region2
            region2 = p[region2]
        return region2
```