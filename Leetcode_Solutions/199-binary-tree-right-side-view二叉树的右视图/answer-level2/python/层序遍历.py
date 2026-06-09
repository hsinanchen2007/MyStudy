```
def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if root is None:
            return None

        res = {}
        stack = [(root, 1)]     # 标记层数
        
        while stack:
            node, level = stack.pop(0)
            res.setdefault(level, node.val)     # 若该层已经有右孩子值，则不再添加

            if node:
                if node.right is not None:
                    stack.append((node.right, level+1))     # 右视图先入队右孩子
                if node.left is not None:
                    stack.append((node.left, level+1))
                    
        return list(res.values())
```
