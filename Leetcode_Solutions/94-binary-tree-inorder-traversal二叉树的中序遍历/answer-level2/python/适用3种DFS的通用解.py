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
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        # 非递归方法
        res = []
        stack = [root]
        while stack:
            node = stack.pop()
            if isinstance(node, TreeNode):
                # 根据不同的DFS顺序，调整3者位置。注意入栈时要反着来
                stack.extend([node.right, [node], node.left])  # 找到最深处的left节点
            elif isinstance(node, list):
                res.append(node[0].val)
        return res

        # 递归方法
        res=[]
        def inorder(node=root):
            if node:
                inorder(node.left)
                res.append(node.val)
                inorder(node.right)
        inorder()
        return res
```
[node]相当于设置了标志位
