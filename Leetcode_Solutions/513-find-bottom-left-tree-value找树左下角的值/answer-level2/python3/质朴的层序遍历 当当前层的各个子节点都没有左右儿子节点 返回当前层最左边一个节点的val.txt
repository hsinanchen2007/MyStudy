思路：如标题所示
注意：不见得是最适合本题的解法 主要的语句都添加了注释 本人菜鸡 以下代码仅供参考
```
class Solution:
	def findBottomLeftValue(self,root):
		deque=[root] #可以from collections import deque来用 但是这题必要性不是很大
		while stack:
			tmp=[] #存储当前层的下一层的节点们
			for i in stack:
				if i.left: #按照先左后右的顺序添加子节点们
					tmp.append(i.left)
				if i.right:
					tmp.append(i.right)
			if tmp: #如果下一层有节点的话就更新deque
				deque=tmp
			else: #没有的话就能得到结果了
				return deque[0].val
```
