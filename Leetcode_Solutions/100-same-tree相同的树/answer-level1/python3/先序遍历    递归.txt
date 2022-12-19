### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        def pre_traversal(node1,node2):
            flag = False
            if not node1 and not node2:
                return True
            elif node1 and node2:
                if node1.val != node2.val:
                    return False
            else:
                return False
            flag = pre_traversal(node1.left,node2.left) & pre_traversal(node1.right,node2.right)
            return flag
        return pre_traversal(p,q)
```