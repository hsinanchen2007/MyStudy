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
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        # 对于每个节点，只有两个可能：在最优路径上/不在最优路径上，因此对每个路径都要计算一次经过他的路径最大长度，
        # 如果大于当前的最大值，更新最大值；
        # 如果某非父节点是叶子结点或者只有左/右子树之一，则可以剪枝
        self.head = root
        if not root:
            return 0
        def dfs(root, depth=0):
            if not root:
                return depth
            return max(dfs(root.left, depth+1), dfs(root.right, depth+1))

        def combineLR(root):
            if not root:
                return 0
            # 剪枝
            if self.head != root and (not root.left or not root.right):
                return 0
            return dfs(root.left) + dfs(root.right)
        
        cur_max = 0
        stack = [root]
        while stack:
            node = stack.pop()
            if node:
                cur_max = max(combineLR(node), cur_max)
                stack.append(node.left)
                stack.append(node.right)
        return cur_max
            
            

```