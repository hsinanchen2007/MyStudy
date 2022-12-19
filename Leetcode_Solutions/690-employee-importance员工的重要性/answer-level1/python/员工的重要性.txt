### 解题思路
此处撰写解题思路

### 代码

```python3
"""
# Employee info
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates
"""
class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        s = 0
        l = len(employees)
        h = {}
        for i in range(l):
            if employees[i].id not in h:
                h[employees[i].id] = i
        idx = h[id]
        s += employees[idx].importance
        sub = employees[idx].subordinates
        while sub:
            sub1 = sub[0]
            del sub[0]
            idx = h[sub1]
            s += employees[idx].importance
            sub2 = employees[idx].subordinates
            for j in range(len(sub2)):
                sub.append(sub2[j])
        return s
```