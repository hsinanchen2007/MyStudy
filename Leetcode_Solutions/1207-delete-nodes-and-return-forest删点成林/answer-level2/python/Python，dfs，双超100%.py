

```python
    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        if not root:
            return []
        if not to_delete:
            return [root]

        def dfs(root, delete=False):  # delete指root是否应当被删除
            if root.left:
                if root.left.val in to_delete:  # 如果左孩子在待删除列表里
                    dfs(root.left, True)  # delete为True并dfs下去
                    root.left = None  # 然后删除这个结点
                else:  # 左孩子结点不在待删除列表
                    if delete:  # 如果root需要删除并且左孩子不为空
                        res.append(root.left)  # 答案添加左孩子结点
                    dfs(root.left)  # delete为False, dfs下去
            if root.right:  # 右孩子逻辑同上
                if root.right.val in to_delete:
                    dfs(root.right, True)
                    root.right = None
                else:
                    if delete:
                        res.append(root.right)
                    dfs(root.right)

        to_delete = set(to_delete)  # 转化为set哈希判断in加速
        if root.val in to_delete:  # 根节点在待删除列表
            res = []
            dfs(root, True)
        else:
            res = [root]
            dfs(root)
        return res
```
