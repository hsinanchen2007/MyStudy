### 解题思路
总体来说就是两棵树同时进行递归，并进行操作，加了各种判断，来构建整棵树，用时和内存都很弱，但是还可行
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        def helper(node1,node2):
            if node1!=None and node2!=None:
                node = TreeNode(node1.val+node2.val)
                l = helper(node1.left,node2.left)
                r=helper(node1.right,node2.right)
                node.left=l
                node.right=r
                return node
            elif node1==None and node2!=None:
                node = TreeNode(node2.val)
                l=helper(None,node2.left)
                r=helper(None,node2.right)
                node.left=l
                node.right=r
                return node
            elif node1!=None and node2==None:
                node = TreeNode(node1.val)
                l=helper(node1.left,None)
                r=helper(node1.right,None)
                node.left=l
                node.right=r
                return node
            elif node1==None and node2==None:
                return None
        root = helper(t1,t2)
        return root

```