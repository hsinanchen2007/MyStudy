### 解题思路
[0] - [1]越小，说明全局分析后去A城市越合适，因此前N个去A后N个去B即可

### 代码

```python3
class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        return sum(list(v[0] if i < len(costs) // 2 else v[1]  for i, v in enumerate(list(sorted(costs, key = lambda costs : costs[0] - costs[1])))))
            
```