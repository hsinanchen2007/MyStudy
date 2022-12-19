### 解题思路
就是让你给新值找个合适位置，可以理解为先在原来的树上搜索新值（肯定搜索不到），当搜索到None就可以插入了；注意插入的方法是返回新的Treenode，为此每次递归都要返回对用节点，相当于重新连接各个节点

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def insertIntoBST(self, root: TreeNode, val: int):
        if(root==None):
            return TreeNode(val)
        if(root.val>val):
            root.left=self.insertIntoBST(root.left,val)
        else:
            root.right=self.insertIntoBST(root.right,val)
        return root
```