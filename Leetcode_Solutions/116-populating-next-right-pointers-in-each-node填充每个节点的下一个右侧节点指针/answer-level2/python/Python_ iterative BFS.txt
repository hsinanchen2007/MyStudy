### 解题思路
模板BFS，与[117. 填充每个节点的下一个右侧节点指针 II](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/submissions/) 相同

### 代码

```python
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root: return root
        q, s = [root], []
        while q:
            while q:
                node = q.pop(0)
                if q: node.next = q[0]
                if node.left: 
                    s.append(node.left)  
                if node.right:
                    s.append(node.right)
            q, s = s, q
        
        return root 
```