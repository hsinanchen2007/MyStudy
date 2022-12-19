### 解题思路
五行搞定

### 代码

```python3
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort(key = lambda x:[-x[0], x[1]])
        res = []
        for p in people:
            res.insert(p[1], p)
        return res
```