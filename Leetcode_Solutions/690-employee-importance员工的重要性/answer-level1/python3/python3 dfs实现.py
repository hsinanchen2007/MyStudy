### 解题思路
就是递归实现dfs就行
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
DFS解题思路：
class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        hashmap={e.id:e for e in employees}
        def dfs(eid):
            emp=hashmap[eid]
            subemp=emp.subordinates
            imp=emp.importance
            for i in subemp:
                imp+=dfs(i)
            return imp
        return dfs(id)
            
```
```python3
看了其他人的利用队列实现bfs：
class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        hashmap = {e.id: e for e in employees}
        queue=[id]
        while queue:
            cur=queue.pop(0)
            e=hashmap[cur]
            res+=e.importance
            for i in e.subordinates:
                queue.append(i)
        return res
```
```python3
DFS：
class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        hashmap = {e.id: e for e in employees}
        return self.dfs(hashmap,id)

    def dfs(self,hashmap,id):
        e=hashmap[id]
        res=e.importance
        for i in e.subordinates:
            res+=self.dfs(hashmap,i)
        return 
```