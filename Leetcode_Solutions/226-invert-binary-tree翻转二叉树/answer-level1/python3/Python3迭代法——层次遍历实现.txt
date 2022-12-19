### 解题思路
利用队列实现二叉树的层次遍历，并对遍历到的每个节点的左右子节点进行位置互换
时间复杂度：O(n)——共n个节点，都要被遍历到
空间复杂度：O(n)——最坏情况下队列中会包含n/2个叶子节点，即O(n/2)，等同于O(n)

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root:
            return None
        queue=[root]
        while queue:
            node=queue.pop(0)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
            node.left,node.right=node.right,node.left
        return root
```