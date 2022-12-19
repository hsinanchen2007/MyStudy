### 解题思路
一、使用hashmap建立员工id与员工的映射关系
二、使用DFS或BFS实现对员工的遍历

时间与空间复杂度均为O(n)，n为员工人数

### 代码
1、DFS递归实现

```python3
class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        hashmap = {e.id: e for e in employees}
        return self.dfs(hashmap,id)

    def dfs(self,hashmap,id):
        e=hashmap[id]
        res=e.importance
        for i in e.subordinates:
            res+=self.dfs(hashmap,i)
        return res

```
2、BFS迭代实现（使用队列）

```python3
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
