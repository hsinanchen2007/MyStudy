### 解题思路
递归思想;循环思想.
见代码注释

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # 函数功能:输入root,翻转此二叉树
    # 递推公式:inverTree(root) =  翻转左子树inverTree(root.left),翻转右子树inverTree(root.right),
    #          root.left = 右子树 and root.right = 左子树
    #终止条件: 节点为None
    # def invertTree(self, root: TreeNode) -> TreeNode:
    #     if not root:
    #         return
    #     root.left,root.right = self.invertTree(root.right),self.invertTree(root.left)
    #     return root

    # 循环.深度优先遍历,只要每层的节点的左右子树均不为None,就交换其左右节点
    # def invertTree(self,root):
    #     if not root:
    #         return
    #     curLayerNode = [root]
    #     while curLayerNode:
    #         nextLayerNode = []
    #         for node in curLayerNode:
    #             node.left,node.right = node.right,node.left
    #             if node.left:
    #                 nextLayerNode.append(root.left)
    #             if node.right:
    #                 nextLayerNode.append(root.right)
    #         curLayerNode = nextLayerNode
    #     return root

    # 循环
    def invertTree(self,root):
        if not root:
            return root
        stack = [root]
        while stack:
            node = stack.pop()
            node.left,node.right = node.right,node.left
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
        return root
```