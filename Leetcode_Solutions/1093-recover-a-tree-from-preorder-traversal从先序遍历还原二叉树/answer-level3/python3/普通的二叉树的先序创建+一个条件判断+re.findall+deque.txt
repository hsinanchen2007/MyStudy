**思路**：先序创建就能满足题目的要求了 findall可以方便地匹配s deque方便FIFO
**注意**：本人菜鸡 语文水平很差 表述方面可能不易理解 主要的语句都添加了注释 以下代码仅供参考 还请大家多多指教
```
from re import findall
from collections import deque
class Solution:
	def recoverFromPreorder(self,S):
		level=deque(len(i) for i in findall(r"\-+",S)) #层次
		level.appendleft(0) #为了下面的helper()中能正确创建结果二叉树的根节点
		t_val=deque(int(i) for i in findall(r"\d+",S)) #结果二叉树中的所有val
		def helper(need):
			if not t_val or level[0]!=need: #普通的先序遍历方式创建二叉树只需要判断not t_val 这里多加了一个level[0]!=need来判断层次是否正确
				return None
			new_root=TreeNode(t_val.popleft()) #创建一个新的树的节点 作为new_root
			level.popleft() #level数组中最左边的一个元素已经用过了 所以出队列
			new_root.left=helper(need+1) #连接当前root的左子树
			new_root.right=helper(need+1) #连接当前root的右子树
			return new_root #返回当前子树
		return helper(0) #参数取0是为了配合根节点的创建
```
