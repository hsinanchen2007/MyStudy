### 解法一: 递归

### 代码
```python
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root == None:
            return 0
        return max(self.maxDepth(root.left), self.maxDepth(root.right))+1 
```

### 方法二: 迭代法 BFS:

```python
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root == None: return 0
        queue = []
        queue.append(root)
        depth = 0
        while queue:
            depth += 1
            level_size = len(queue) # 记录下层 size, 然后将该层的每一个元素弹出,并将其子节点加入队列
            for i in range(level_size):
                cur = queue.pop(0)
                if cur.left != None:
                    queue.append(cur.left)
                if cur.right != None:
                    queue.append(cur.right)
        return depth
```

### 方法三: 迭代法,DFS:
```python
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root == None: return 0
        stack = [(1, root)]
        max_depth = 1
        while stack:
            pair = stack.pop()
            node = pair[1]
            max_depth = max(pair[0], max_depth)
            if node.right != None:
                stack.append((pair[0]+1, node.right))
            if node.left != None:
                stack.append((pair[0]+1, node.left))
        return max_depth
```











```