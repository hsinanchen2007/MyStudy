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
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root == None:
            return []
        
        queue = []
        queue.append(root)
        queue.append('r')

        result = []
        cur = []
        while len(queue) != 0:
            temp = queue[0]
            queue.pop(0)
            
            if temp != 'r':
                cur.append(temp.val)
                if temp.left != None:
                    queue.append(temp.left)
                if temp.right != None:
                    queue.append(temp.right)
            else:
                result.append(cur)
                cur = []
                if len(queue) != 0:
                    queue.append('r')
        return result



```