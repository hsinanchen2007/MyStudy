思路：见标题
注意：本人菜鸡 空间上的效率不是很好 以下代码仅供参考(主要语句都添加了注释) 还请大家多多指教
```
from collections import deque #这边使用队列的原因是因为方便后序遍历的左插入操作
class Solution:
	def pathSum(self,root,sum):
		ans=[]
		if root: #如果根节点就是None就没有必要做下面的工作了
			def helper(root,goal,_sum): #goal就是pathSum()中的sum参数 _sum表示遍历到当前节点的sum
				if not root.left and not root.right: #说明当前节点已经是叶子节点了
					t=deque()
					if _sum+root.val==goal: #如果这条从根节点到当前叶子节点的路径满足要求就记录当前叶子节点的val
						t.append(deque([root.val]))
					return t
				a,b=deque(),deque()
				if root.left: #如果当前节点有左子树
					a=helper(root.left,goal,_sum+root.val)
					for i in a: #后续满足条件的路径组成的deque 如果没有满足条件的路径就是个空的deque -> a不会发生改变
						i.appendleft(root.val) #将当前节点的val记录到各个路径之中去(*插在最左边)
				if root.right: #同上
					b=helper(root.right,goal,_sum+root.val)
					for i in b:
						i.appendleft(root.val)
				return a+b #将左子树的可行路径和右子树的可行路径加起来一起返回
			ans=helper(root,sum,0)
		return ans
```
