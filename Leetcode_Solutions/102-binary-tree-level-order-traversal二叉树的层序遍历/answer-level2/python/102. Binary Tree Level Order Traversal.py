```
思路: 
L = [] # 栈的层级代表该数的层级
level = 0 # 初始化该level为0

- 1. if len(L) == level: 新建个层级 L = [[]]
- 2. 数据: L[level].append(node.val)
- 3. 处理左子树, 和1,2步骤一样 唯一不同的是level + 1
-    处理右子树, 和1,2步骤一样 唯一不同的是level + 1
```

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        
        L = []
        def traverse(node, level):
            if node:
                if len(L) == level:
                    L.append([])
                if node:
                    L[level].append(node.val)

                    traverse(node.left, level + 1)
                    traverse(node.right, level + 1)
        traverse(root, 0)
        return L
        
```
