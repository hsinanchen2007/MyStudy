
新加入的值始终是最大数的数组形式的最右边, 因此可以理解最终的加入点始终会在最右边,
因此可以层次遍历二叉树, 找到合适的右子树节点插入
```
def insertIntoMaxTree(self, root: TreeNode, val: int) -> TreeNode:
    # A树为空的情况
    if root is None:
        return TreeNode(val)
    
    def helper(parent_node: TreeNode, curr: TreeNode, val: int):
        if val > curr.val:
            tmp_tree_node = TreeNode(val)
            tmp_tree_node.left = curr
            parent_node.right = tmp_tree_node
            return
            
        if curr.right is None:
            tmp_tree_node = TreeNode(val)
            curr.right = tmp_tree_node
            return
        
        helper(curr, curr.right, val)
    
    # 层次遍历, 判断当前点是否大于根节点 这个地方单独运行一次, 用于保存根节点
    if val > root.val:
        root_node = TreeNode(val)
        root_node.left = root
        return root_node
    else:
        # 该值并不比根节点大, 那么就需要递归二叉树
        if root.right is None:
            tmp_node = TreeNode(val)
            root.right = tmp_node
        else:
            helper(root, root.right, val)
        
        return root
```