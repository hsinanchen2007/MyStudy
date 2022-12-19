```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        res = []
        dic = collections.defaultdict(int)
        def dfs(root, node, to_delete):
            if node == None: return
            if node.left is None and node.right is None:
                if root.val not in to_delete and root.val not in dic:
                    res.append(root)
                    dic[root.val] = 1
                return
            if node.val in to_delete:
                if root.val not in dic and root.val not in to_delete:
                    res.append(root)
                    dic[root.val] = 1
                dfs(node.left, node.left, to_delete)
                dfs(node.right, node.right, to_delete)
            else:
                dfs(root, node.left, to_delete)
                dfs(root, node.right, to_delete)

            if node.left and node.left.val in to_delete: node.left = None
            if node.right and node.right.val in to_delete: node.right = None
        dfs(root, root, to_delete)
        return res
                



```