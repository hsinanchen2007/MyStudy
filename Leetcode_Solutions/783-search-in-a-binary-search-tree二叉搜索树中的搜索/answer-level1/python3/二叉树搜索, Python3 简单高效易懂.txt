```
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        if root is None: return root
        node = root
        while node is not None:
            if val < node.val:
                node = node.left
            elif val > node.val:
                node = node.right
            else:
                return node
        return None
```


# 复杂度分析
时间复杂度： O(log(n));

空间复杂度： O(1)