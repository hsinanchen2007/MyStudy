### 解题思路
树的直径也即在具有最多结点数目的某条路径上的的路径长度。
直径 = 最多结点数 - 1

树中任意一条路径都可以看作是某个根结点连接的左右子树。

为找到最多的结点数，采用递归方式对每个结点进行遍历：
1. 计算出以此结点为根结点的左右子树上结点总和，也即此结点连接的路径长度+1。并更新最大路径长度
2. 计算此结点的深度，也即左右子树深度的最大值+1

初始值：考虑特殊情况，若为空树，则最大路径长度为0，而递归后返回的值为结点数-1，故需设置成1。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        
        self.max_path = 1
        
        # get depth of every node
        def node_depth(node):
            if not node:
                return 0

            l = node_depth(node.left)
            r = node_depth(node.right)
            # update node numbers of max path
            self.max_path = max(self.max_path, l + r + 1)

            return max(l, r) + 1

        # travel every node to update max path
        node_depth(root)

        return self.max_path - 1        
```