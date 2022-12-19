思路：见标题
注意：没怎么往非递归方向想(本人菜鸡) 但通过之后看了看有不少的非递归题解 一般来说有迭代且不复杂就迭代吧 以下代码仅供参考
```
class Solution:
	def flatten(self,root):
		if root:
			def helper(root):
				if not root.left and not root.right: #表示这是一个叶子节点
					return root
				if root.left:
					left_tail=helper(root.left) #左子树经过变化后的叶子节点Node1
					if root.right:
						right_tail=helper(root.right) #右子树经过变化后的叶子节点Node2
						root.left,root.right,left_tail.right=None,root.left,root.right
						#当前节点原先右子树的根节点接在Node1上,这样子左子树上就是满足条件的展开了
						#之后就把当前节点的左子树清空 右子树换成原来的左子树就可以了
					else:
						right_tail=left_tail #为下面的return做准备
						root.left,root.right=None,root.left #道理还是和上面一样的 就是这种情况要考虑的内容少了些
					return right_tail #Node2
				return helper(root.right)
			helper(root)
```
