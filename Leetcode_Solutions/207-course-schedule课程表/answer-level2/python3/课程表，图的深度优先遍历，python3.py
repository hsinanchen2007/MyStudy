### 解题思路
用son记录每个节点的孩子节点
用flag数组记录每个节点的访问状态
如果第i个节点访问过程中没有出现环，使flag[i] = -1
当前遍历过程中的每个节点都标记的flag标为1
如果遍历到flag为-1的节点直接返回true，遍历到1说明存在环，返回False
递归调用

### 代码

```python3
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        son = {i:[] for i in range(numCourses)}
        flag = [0 for i in range(numCourses)]

        for m, n in prerequisites:
            son[n].append(m)

        def dfs(i, flag):
            if flag[i] == -1: return True
            if flag[i] == 1: 
                return False
            flag[i] = 1
            for child in son[i]:
                if not dfs(child, flag): return False
            flag[i] = -1
            return True
    
        for i in range(numCourses):
            if not dfs(i, flag): return False
        return True
```