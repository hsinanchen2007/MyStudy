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
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0

        count = 0
        tree = [root]
        
        while tree:
            for i in range(len(tree)):
                tmp = tree.pop(0)
                
                if tmp.left:
                    tree.append(tmp.left)
                if tmp.right:
                    tree.append(tmp.right)
                
            count += 1
                
                
        return count
                
           
```