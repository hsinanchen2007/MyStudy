```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        node_list, result_list = [root] if root else [], []
        while node_list:
            node = node_list.pop()
            result_list.append(node.val)
            if node.right:
                node_list.append(node.right)
            if node.left:
                node_list.append(node.left)
        return result_list
        
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        return [root.val] + self.preorderTraversal(root.left) + self.preorderTraversal(root.right) if root else []


```
