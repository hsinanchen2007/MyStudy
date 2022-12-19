```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
	def findFrequentTreeSum(self, root: TreeNode) ->List[int]:
		# key: sum_val
		# val: cnt
		res_dic = collections.defaultdict(int)
		def sum_solve(node):
			if not node: return 0
			temp_sum = sum_solve(node.left) + node.val + sum_solve(node.right)
			res_dic[temp_sum] += 1
			return temp_sum
		if not root: return []
		sum_solve(root) # res_dic = {2: 2, -5: 1}
		max_cnt = 0
		for cnt in res_dic.values():
			max_cnt = max(max_cnt, cnt)
		return [key for key, cnt in res_dic.items() if cnt == max_cnt]
```