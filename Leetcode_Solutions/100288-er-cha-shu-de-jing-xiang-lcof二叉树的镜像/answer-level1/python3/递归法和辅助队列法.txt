### 解题思路


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mirrorTree(self, root: TreeNode) -> TreeNode:
        """
        递归法
        """
        if not root:
            return None
        node = root.left
        root.left = self.mirrorTree(root.right)
        root.right = self.mirrorTree(node)
        return root
        
    def mirrorTree_queue(self, root: TreeNode) -> TreeNode:
        """
        辅助队列法：广度优先遍历该树，每遍历一个节点，就交换该节点的左右子节点，
        最后返回该树
        
        """
        if not root:
            return None
        queue = deque([root])
        while queue:
            node = queue.popleft()
            if node.left: # 如果还存在左子节点，继续遍历交换
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
            node.left, node.right = node.right, node.left
        return root
```