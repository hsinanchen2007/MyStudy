###### 把树合并到t2中，存在三种情况：
- 1---t1,t2都有节点 -->把t1加到t2，并继续向下合并； 
- 2---t1没有节点-->t2子树不变就可以了；  
- 3---t1有节点，t2没有-->生成t2结点，并继续向下合并。

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mergeTrees(self, t1: TreeNode, t2: TreeNode) -> TreeNode:
        def merge(src, dst):
            if src is None:
                return
            dst.val += src.val
            if dst.left is None and src.left:
                dst.left = TreeNode(0)
            merge(src.left, dst.left)
            if dst.right is None and src.right:
                dst.right = TreeNode(0)
            merge(src.right, dst.right)

        if not t1 and not t2:
            return None
        # 需要有个根节点
        if t2 is None:
            t2 = TreeNode(0)
        merge(t1, t2)
        return t2
```
