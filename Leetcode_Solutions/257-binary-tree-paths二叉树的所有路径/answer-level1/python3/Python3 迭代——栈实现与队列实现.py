二者略有不同

### 解题思路
一、DFS：先序遍历，用栈实现

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        if root is None:
            return []
        l=[]
        stack=[(root,str(root.val))]
        while stack:
            #注意此处为从栈顶弹出
            node,s=stack.pop()
            if node.left is None and node.right is None:
                l.append(s)
            if node.right:
                stack.append((node.right,s+'->'+str(node.right.val)))
            if node.left:
                stack.append((node.left,s+'->'+str(node.left.val)))
        return l
```

### 解题思路
二、BFS：层次遍历，用队列实现

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        if root is None:
            return []
        l=[]
        queue=[(root,str(root.val))]
        while queue:
            #注意此处为从队头弹出
            node,s=queue.pop(0)
            if node.left is None and node.right is None:
                l.append(s)
            if node.left:
                queue.append((node.left,s+'->'+str(node.left.val)))
            if node.right:
                queue.append((node.right,s+'->'+str(node.right.val)))
        return l
```