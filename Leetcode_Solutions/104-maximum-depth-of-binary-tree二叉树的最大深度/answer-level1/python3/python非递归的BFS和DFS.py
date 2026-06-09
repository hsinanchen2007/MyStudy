BFS，层次遍历最后得到的深度就是最大的深度
```
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        # BFS
        if root is None:
            return 0
        queue = [(1, root)]
        while queue:
            depth, node = queue.pop(0)
            if node.left:
                queue.append((depth+1,node.left))
            if node.right:
                queue.append((depth+1,node.right))
        return depth
```

DFS与BFS有两点不同：
1. 最后得到的深度不一定是最大深度，所以要用max判断
2. DFS（先序遍历）节点右孩子先入栈，左孩子再入栈`
```
class Solution:
    def maxDepth(self, root: TreeNode) -> int:    
        # DFS
        if root is None:
            return 0
        stack = [(1, root)]
        depth = 0
        while stack:
            cur_dep, node = stack.pop()
            depth = max(depth, cur_dep)
            if node.right:
                stack.append((cur_dep+1,node.right))
            if node.left:
                stack.append((cur_dep+1,node.left))
        return depth
```


