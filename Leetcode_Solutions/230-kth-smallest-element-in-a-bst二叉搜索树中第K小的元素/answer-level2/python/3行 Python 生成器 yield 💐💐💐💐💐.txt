```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthSmallest(self, root, k):
        from itertools import chain, islice
        def gen(x): yield from chain(gen(x.left), [x.val], gen(x.right)) if x else ()
        return next(islice(gen(root), k - 1, k))
```
- 本题利用了迭代器
- chain 函数可以组合多个迭代器，islice 函数对迭代器做切片操作
- 此题常规解法 中序遍历 还是需要了解下的
	```python
	# Definition for a binary tree node.
	# class TreeNode(object):
	#     def __init__(self, x):
	#         self.val = x
	#         self.left = None
	#         self.right = None

	class Solution(object):
	    def kthSmallest(self, root, k):
		"""
		:type root: TreeNode
		:type k: int
		:rtype: int
		"""
		res = []
		self.visitNode(root, res)
		return res[k - 1]

	    # 中序遍历
	    def visitNode(self, root, res):
		if root is None:
		    return
		self.visitNode(root.left, res)
		res.append(root.val)
		self.visitNode(root.right, res)
	```

