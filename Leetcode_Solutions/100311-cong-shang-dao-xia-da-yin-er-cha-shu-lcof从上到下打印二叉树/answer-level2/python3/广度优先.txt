### 解题思路
如题

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        node_list = []
        tree = [root]
        while tree != []:
            node = tree.pop(0)
            if node:               
                node_list.append(node.val)
                if node.left:
                    tree.append(node.left)
                if node.right:
                    tree.append(node.right)
        return node_list
```