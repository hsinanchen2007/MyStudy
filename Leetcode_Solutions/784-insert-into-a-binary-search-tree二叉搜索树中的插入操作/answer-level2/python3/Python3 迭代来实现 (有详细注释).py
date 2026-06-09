```
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        """
        注意: 插入的节点一定是叶子节点
        """
        if root is None:
            # 如果根节点为空 直接让root指向新创建的节点
            root = TreeNode(val)
            return root
        
        curr = root
        parent = curr
        # 寻找val的父节点
        while curr is not None:
            # 记录比较结果 下面要用到
            cmp = val - curr.val
            parent = curr
            if cmp > 0:
                # val 大于当前节点的值 往curr的右子节点找
                curr = curr.right
            elif cmp < 0:
                # val小于当前节点的值 往curr的右子节点找
                curr = curr.left
            else:
                # 如果相等 直接覆盖 当然也可以不做任何处理 可以直接返回root
                curr.val = val
                return root
            
        node = TreeNode(val)
        # 根据cmp比较结果设置左或者右子节点
        if cmp > 0:
            parent.right = node
        else:
            parent.left = node
            
        return root
```

# 复杂度分析
时间复杂度: O(log(n))
空间复杂度: O(1)
