思路：见标题
注意：要注意理解二叉搜索树的意义(比如我 我是上课没好好听讲 因为没理解好错了太多次数了)
```
class Solution:
	def isValidBST(self,root):
		ans=True
		if root:
			def helper(root):
				nonlocal ans #注意一下需要使用nonlocal
				root_val=root.val
				a,d=[root_val]*2 #helper函数的返回值是二元列表 分别表示以当前节点作为根节点的树的最小val和最大val
				if root.left:
					a,b=helper(root.left) #这边要注意更新a
					if b>=root_val: #说明已经不是一个合规范的二叉搜索树
						ans=False
				if root.right:
					c,d=helper(root.right) #这边要注意更新d
					if c<=root_val: #同理
						ans=False
				return [a,d]
			helper(root)
		return ans
```
