### 解题思路
1. 若根结点为None，深度为0；
2. 否则将根结点及其深度入栈；
3. 若栈非空，第一个元素出栈；
4. 若该元素左右孩子为None，则为叶子结点，返回其对应深度；
5. 若左结点不为空，则将左结点与其深度入栈；
6. 若右结点不为空，则将右结点与其深度入栈；
   ！注意：先入先出，保证深度由浅到深，遇到满足条件的，立即返回；

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        stack= [(root, 1)]
        while stack:
            root,depth = stack.pop(0)
            if not root.left and not root.right:
                return depth
            if root.left:
                stack.append((root.left, depth + 1))
            if root.right:
                stack.append((root.right, depth + 1))
        
```