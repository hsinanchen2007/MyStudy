### 解题思路
主要思路用用bfs
数据结构用字典记录每个深度最右边的节点

### 代码
```python3
class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:    
        r = {}
        stack = [(root,0)]
        while stack:
            n,d = stack.pop()            
            if n :
                r.setdefault(d,n.val)
                stack.append((n.left,d+1))
                stack.append((n.right,d+1))
        return [r[i] for i in r]
```