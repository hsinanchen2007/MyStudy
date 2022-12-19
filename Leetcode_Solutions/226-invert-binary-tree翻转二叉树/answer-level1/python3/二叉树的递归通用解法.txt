二叉树的递归通用解法：
        1、确定递归结束条件，
        2、左子树做完，
        3、右子树做完，
        4、连着根做完，
        5、返回根；
2，3，4步骤顺序可任意调换，调换原则：先序遍历，中序遍历，后序遍历；此题为后序

def invertTree(self, root: TreeNode) -> TreeNode:
        if root is None:
            return None
        root.left, root.right = self.invertTree(root.right), self.invertTree(root.left)
        return root
