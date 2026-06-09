```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
	def findLeaves(self, root: TreeNode) -> List[List[int]]:
		# like layer traverse
		# key: layer
		# val: [layerVal, ...]
		# Time complexity: O(N)
		# Space complexity: O(1)
		layer_dic = collections.defaultdict(list)
		def solve(node):
			if not node: return 0
			layer = max(solve(node.left), solve(node.right)) + 1
			layer_dic[layer].append(node.val)
			return layer
		solve(root)
		return [val for val in layer_dic.values()]
```