### 解题思路
遍历的框架不用多说了！！只要是树的题目一般就是这个框架，先写出来
重要的是对当前的节点的操作！！需要你自己实现细节，这道题只需要判断是不是叶节点即可！
【这道题前中序三种遍历都可以AC，递归和迭代的版本都需要会】
```python3
def help(root):
    if root is None:
        return
    //前序遍历（对当前的根结点的操作）
    help(root.left)
    //中序遍历（对当前的根结点的操作）
    help(root.right)
    //后序遍历（对当前的根结点的操作）
```
### 代码(中序递归)

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        
        def help(root, leves):
            if root is None:
                return
            if root.left is None and root.right is None:
                leves.append(root.val)
            help(root.left,leves)
            help(root.right, leves)
            
            return leves

        return help(root1, []) == help(root2, [])
        
```
### 代码（中序迭代）
```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        
        def help(root):
            stack, res = [], []
            while root or stack:
                while root:
                    stack.append(root)
                    root = root.left
                root = stack.pop()
                if root.left is None and root.right is None:# 判断是否是叶子节点
                    res.append(root.val)
                root = root.right
            return res
        
        return help(root1) == help(root2)
```