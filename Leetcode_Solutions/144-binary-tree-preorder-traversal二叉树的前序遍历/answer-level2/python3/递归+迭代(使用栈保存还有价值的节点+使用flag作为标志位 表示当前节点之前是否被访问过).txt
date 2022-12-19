1.递归实现(就是深度优先搜索)
```
class Solution:
	def preorderTraversal(self,root):
		ans=[]
		def helper(root):
			if root:
				ans.append(root.val) #记录当前节点的val
				helper(root.left) #深度优先访问当前节点的左儿子节点
				helper(root.right) #当前节点的左子树访问完毕 深度优先访问当前节点的右儿子节点
		helper(root)
		return ans
```

2.迭代实现(思路见标题 主要的语句都添加了注释 以下代码仅供参考 请大家多多指教)
```
class Solution:
	def preorderTraversal(self,root):
		ans=[]
		if root:
			stack=[root]
			flag=True #用以判断当前stack[-1]的树的节点是否未访问的标志位
			while stack:
				tmp=stack[-1]
				if flag: #True表示之前没有访问过
					ans.append(tmp.val) #根据前序遍历的规则 将val加入到ans中
					if tmp.left: #如果左儿子节点存在 就将左儿子节点压入栈中 作为下一次循环访问的节点
						stack.append(tmp.left)
					else: #如果不存在 那么下一次循环将会试探当前节点有没有右儿子节点
						flag=False #和上一句对应 那时当前节点因为已经被访问了 所以将flag标志位置为False
				else: #False表示之前访问过
					stack.pop() #不管有没有右儿子节点 这个节点都已经没有保留的必要了
					if tmp.right: #如果右儿子节点存在 就将右儿子节点压入栈中 作为下一次循环访问的节点
						stack.append(tmp.right)
						flag=True #因为下次注定访问当前节点的右儿子节点 而它之前未被访问过 所以将flag标志位置为True
		return ans
```
