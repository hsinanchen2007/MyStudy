```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def getParent(node, p, tempArr):
            if node == None: return []
            if node.val == p.val:
                return tempArr + [p]
            else:
                tempArr.append(node)
                left_temp = getParent(node.left, p, tempArr)
                right_temp = getParent(node.right, p, tempArr)
                tempArr.pop()
                if left_temp != []: return left_temp
                else: return right_temp
        parent_p = getParent(root, p, [])
        parent_q = getParent(root, q, [])
        p_index, q_index = 0, 0
        while p_index < len(parent_p) and q_index < len(parent_q) and parent_p[p_index].val == parent_q[q_index].val:
            q_index += 1
            p_index += 1
        return parent_p[p_index - 1]

```