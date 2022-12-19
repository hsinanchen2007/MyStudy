### 解题思路
记录好前一个节点，然后指向即可。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        tmpnode = None
        stack = [(root, False)]
        while stack:
            node, flag = stack.pop()
            if node:
                if flag:
                    # print(node.val)
                    node.right = tmpnode
                    tmpnode = node
                    node.left = None
                else:
                    stack.append((node, True))
                    stack.append((node.left, False))
                    stack.append((node.right, False))




                    
        

```