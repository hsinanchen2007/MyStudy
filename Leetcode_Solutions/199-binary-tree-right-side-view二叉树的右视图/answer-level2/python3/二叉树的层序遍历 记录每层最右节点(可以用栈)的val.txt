思路：如标题
```
class Solution:
	def rightSideView(self,root):
		ans=[] #记录结果
		if root:
			stack=[root] #首先将根节点入栈
			while stack:
				tmp_stack=list() #用来更新每一层的栈
				for i in stack:
					if i.left:
						tmp_stack.append(i.left)
					if i.right:
						tmp_stack.append(i.right)
				ans.append(stack.pop().val) #将每层最右边一个节点的val保存到ans中
				stack=tmp_stack
		return ans
```
