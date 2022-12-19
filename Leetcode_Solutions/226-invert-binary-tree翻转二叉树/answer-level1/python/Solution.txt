### 解题思路
此处撰写解题思路

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root == None:
            return None
        
        queue = []
        queue.append(root)

        while len(queue) > 0:
            cur_node = queue[0]
            queue.pop(0)
            cur_node.right,cur_node.left = cur_node.left,cur_node.right
            if(cur_node.left != None):
                queue.append(cur_node.left)
            if(cur_node.right != None):
                queue.append(cur_node.right)
        return root

```