### 解题思路
- **如何找到叶子？
递归过程中发现某个节点左右孩子都是None，则他是叶子**
- **如何找到左孩子，并求和？
进入左孩子查找时，传入信号表明该子树是左孩子，如果发现又是叶子，则累加**


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        self.sum_leaves=0
        def count(root,position):
            if not root:
                return
            if not root.left and not root.right:
                if position==1:
                    self.sum_leaves+=root.val
            count(root.left,1)
            count(root.right,0)
        count(root,0)
        return self.sum_leaves
        
```