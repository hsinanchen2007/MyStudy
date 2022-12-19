思路：方阵对于正对角线有对称关系
注意：排序的O(nlogn)的时间复杂度确实不太顶 追求速度的还是不推荐 贴出来单纯希望给大家多个思路
```
from functools import cmp_to_key
class Solution:
	def findDiagonalOrder(self,matrix):
		_all_=[]
		for x in range(len(matrix)): #首先简单地遍历来收集各个数据
			for y in range(len(matrix[0])):
				_all_.append((x,y,matrix[x][y])) #三元元组 (row_index,column_index,val)
		def cmp(a,b): #自定义排序规则
			a_x,a_y,_=a
			b_x,b_y,_=b
			a_all,b_all=a_x+a_y,b_x+b_y
			if a_all<b_all: #row_index+column_index比较小的肯定是先遍历到的
				return -1
			elif a_all>b_all:
				return 1
			else:
				if a_all%2: #如果不是偶数行(准确来说应该叫做对角线行 以0为起点)
					if a_y<b_y: #可以对照示例图看一下
						return 1
					return -1
				else:
					if a_y<b_y:
						return -1
					return 1
		return [i for _,_,i in sorted(_all_,key=cmp_to_key(cmp))] #排序 输出val
```
