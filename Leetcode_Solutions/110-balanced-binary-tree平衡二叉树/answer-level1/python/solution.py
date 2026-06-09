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
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def getHeight(node):
            if node == None:
                return 0
            left = getHeight(node.left)
            right = getHeight(node.right)
            return max(left,right) + 1
        
        def check(node):
            queue = []
            queue.append(node)

            while len(queue) != 0:
                cur_node = queue[0]
                queue.pop(0)
                if abs(getHeight(cur_node.left) - getHeight(cur_node.right)) >= 2:
                    return False
                if(cur_node.left != None):
                    queue.append(cur_node.left)
                if(cur_node.right != None):
                    queue.append(cur_node.right)
            return True
        
        if root == None:
            return True
        return check(root)



```