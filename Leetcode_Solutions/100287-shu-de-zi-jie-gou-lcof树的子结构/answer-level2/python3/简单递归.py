A中的每个节点都可能是b的根节点。
然后递归！ 左子树相同 右子树也要相同

```
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        if not A or not B:
            return False
        nodesA = []
        self.inorder(A, nodesA)
        for node in nodesA:
            if node.val == B.val:
                if self.is_sub(node, B):
                    return True
        return False

    def inorder(self, node: TreeNode, nodes_list: List[str]):
        # 返回前序遍历的
        if node is None:
            return
        self.inorder(node.left, nodes_list)
        nodes_list.append(node)
        self.inorder(node.right, nodes_list)

    def is_sub(self, na: TreeNode, nb: TreeNode):
        if na is None and nb is None:
            return True
        if na is None and nb is not None:
            return False
        # 下面是没必要的 本来na的节点就是比nb的多!
        if na is not None and nb is None:
            return True
        if na.val != nb.val:
            return False
        return self.is_sub(na.left, nb.left) and self.is_sub(na.right, nb.right)

```
