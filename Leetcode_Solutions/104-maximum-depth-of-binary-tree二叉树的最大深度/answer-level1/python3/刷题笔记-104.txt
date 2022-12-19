# 题目要点
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
叶子节点是指没有子节点的节点。

# 递归（DFS）
中心思想是先遍历一侧子树，再遍历另一侧子树。
示例代码先遍历了左子树。
```python []
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        
        left = self.maxDepth(root.left)
        right = self.maxDepth(root.right)
        return max(left, right) + 1
```
返回值+1表示当前到达的深度。

# 迭代（DFS）
中心思想是把二叉树某个节点的左子节点和右子节点添加到栈中，通过迭代的方式找到最大深度。

```python []
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        
        stack = []
        stack.append((root, 1))
        depth = 1
        while stack:
            node, cur_depth = stack.pop()
            depth = max(depth, cur_depth)
            
            if node.left:
                stack.append((node.left, cur_depth+1))
            if node.right:
                stack.append((node.right, cur_depth+1))
                
        return depth
```


