看到二叉树的题目，首先想到的是递归的方法。
1、判断一棵树是否为空树，空树反转还是空树

```
def invertTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        left = self.invertTree(root.left)
        right = self.invertTree(root.right)
        # 左右子树进行反转
        root.right = left
        root.left = right
        return root

```
