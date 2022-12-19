1.递归实现
```
class Solution: #递归法
	def inorderTraversal(self,root):
		ans=[]
		if root:
			def helper(root):
				if root.left:
					helper(root.left)
				ans.append(root.val)
				if root.right:
					helper(root.right)
			helper(root)
		return ans
```

2.从递归->迭代(主要的语句都添加了注释 请大家多多指教)
注:这种解法虽然达到了目的 但是破坏了原有的树的结构(我太菜了) 并不推荐 以下代码仅供参考
```
class Solution: #迭代法
	def inorderTraversal(self,root):
		if not root:
			return []
		stack=[root] #使用栈保存还没有读取val的树的节点
		ans=list()
		while stack:
			tmp=stack[-1]
			if tmp.left: #如果当前节点有左儿子节点 就优先将左儿子节点加入栈中
				stack.append(tmp.left)
				tmp.left=None #切断当前节点与其左儿子节点的联系 这样子之后回到当前节点的时候就会直接去找它的右子树了
			else:
				stack.pop() #当前节点的左子树已经处理完毕 本质上这个节点已经没用了 所以出栈
				ans.append(tmp.val) #因为中序遍历 所以在这边读取当前节点的值
				if tmp.right: #如果当前节点有右儿子节点 就将右儿子节点入栈
					stack.append(tmp.right)
		return ans
```

