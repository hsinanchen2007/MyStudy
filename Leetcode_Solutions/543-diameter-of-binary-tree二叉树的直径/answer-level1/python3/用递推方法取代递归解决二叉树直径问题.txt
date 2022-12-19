### 解题思路
也就是把递归变成了递推
第一个while循环用栈和队列将二叉树变成数组（bfs），第二个循环用栈，相当于动态规划，每个节点都存储当前节点到页节点的长度，那当前节点的直径就是（左子节点长度+右子节点长度+1）。

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
        if not root:
            return 0
        max_len = 0
        left = 0
        right = 0
        t_queue = [root]
        t_stack = []
        while len(t_queue) != 0:
            node = t_queue.pop()
            node.val = 0
            if node.left:
                t_queue.insert(0, node.left)
            if node.right:
                t_queue.insert(0, node.right)
            t_stack.append(node)
        while len(t_stack) != 0:
            node = t_stack.pop()
            left = node.left.value if node.left else 0
            right = node.right.value if node.right else 0
            node.value = max(left, right) + 1
            max_len = max(max_len, left + right + 1)
        return max_len - 1

```