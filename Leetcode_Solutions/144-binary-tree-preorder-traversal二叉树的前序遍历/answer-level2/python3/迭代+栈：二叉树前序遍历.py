### 解题思路
前序遍历是先访问根节点、再访问左子树、再访问右子树
首先将当前根节点的值放入栈res中，
假如当前节点的左子树和右子树都存在，将右节点先存入栈stack中，将左节点设为d下一次迭代的根节点
如果当前节点的左子树不存在，右子树存在，将下一次迭代的根节点设为右节点，
如果当前节点的左、右子树均不存在，该节点为叶节点，访问栈stack，查看是否存在右节点，然后将其设为下一次迭代的根节点。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        #储存右节点
        stack = []
        #存储当前节点的值
        res = []
        
        while root :
            res.append(root.val)

            if root.left:
                if root.right:
                    stack.append(root.right)
                root = root.left
            elif root.right:
                root = root.right
            elif stack:
                root = stack.pop()
            else:
                root = None
        
        return res
```