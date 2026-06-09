### 解题思路
create_new_tree用于中序遍历 把结果暂存Tree数组 然后提取Tree数组 重新建树 同时Tree的Tree[0]为新树的根节点

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        Tree=[]
        def create_new_tree(temp ):
            if temp.left!=None: create_new_tree(temp.left)
            new_Node = TreeNode(temp.val)
            Tree.append(new_Node)
            if temp.right!=None: create_new_tree(temp.right)
        create_new_tree(root)
        new_root = Tree[0]
        for i in Tree[1:]:
            new_root.right = i
            new_root=i
        return Tree[0]
```