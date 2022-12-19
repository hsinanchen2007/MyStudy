### 解题思路
用总的服务器数量减去孤立服务器数量

### 代码

```python3
class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        def col(n):
            return [_[n] for _ in grid]
        tt=0        
        for row in grid:
            if row.count(1)==1:
                if col(row.index(1)).count(1)==1:
                    tt+=1
        return sum(map(lambda x:x.count(1),grid))-tt
```