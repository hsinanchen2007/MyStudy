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
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        queue = []
        queue.append([[root],root])
        result = []

        while len(queue) != 0:
            cur_path = queue[0][0]
            cur_node = queue[0][1]
            queue.pop(0)
            if cur_node.val == p.val or cur_node.val == q.val:
                result.append(cur_path)
                if len(result) == 2:
                    break
            
            if cur_node.left != None:
                left_path = cur_path[:]
                left_path.append(cur_node.left)
                queue.append([left_path,cur_node.left])
            if cur_node.right != None:
                right_path = cur_path[:]
                right_path.append(cur_node.right)
                queue.append([right_path,cur_node.right])
        
        i = 0
        while i < min(len(result[0]), len(result[1])):  
            if result[0][i].val != result[1][i].val:
                break
            i += 1
        return result[0][i-1]
```