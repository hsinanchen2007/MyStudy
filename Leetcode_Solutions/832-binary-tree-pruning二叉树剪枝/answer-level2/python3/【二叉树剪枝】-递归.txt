 题目理解：删掉所有仅包含0的子树

###### 后序遍历二叉树，对于处于叶子节点的0是要删除的（通过返回None给调用者去更新它的孩子指针，当调用者左右孩子都被置成None，它也就变成叶子节点了）
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pruneTree(self, root: TreeNode) -> TreeNode:
        def dfs(root):
            if root:
                if root.left:
                    root.left = dfs(root.left)
                    
                if root.right:
                    root.right = dfs(root.right)
                
                if root.val == 0 \
                    and root.left is None \
                    and root.right is None:
                        return None
                return root
        
        root = dfs(root)
        return root
```
