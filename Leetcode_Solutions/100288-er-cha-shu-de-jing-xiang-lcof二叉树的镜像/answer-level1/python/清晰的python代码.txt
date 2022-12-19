### 解题思路
前序遍历这棵树的每一个节点，如果遍历到的节点有子节点，就交换它的两个子节点。
当交换完所有的非叶节点的子节点就得到这棵树的镜像。


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        
        if not root: #p 判断节点是否为空
            return None
        if not root.left and not root.right: # 判断是否是叶节点
            return root
            
        root.left, root.right = root.right, root.left # 交换非叶节点的两个子节点
        if root.left:
            self.mirrorTree(root.left)
        if root.right:
            self.mirrorTree(root.right)
        return root
        
```