### 解题思路
此处撰写解题思路
用类似堆排的思路，内存消耗小，但是用时长，毕竟处理long数的时候，才能体现出来。
当前的时间复杂为O(nlogk)
### 代码

```python
class Solution(object):

	# 父节点index
	def parent_id(self, n):
		return (n - 1) // 2


	# 左儿子的下标
	def lef_id(self,n):
		return 2*n +1

	# 右儿子的下标
	def rigth_id(self,n):
		return 2*n +2

	def get_item(self,arr,k):

		for i in range(1,k):
			t = i
			while t!=0 and arr[self.parent_id(t)] < arr[t]:  # 子节点大于父节点的话，则需要替换
				temp = arr[t]
				arr[t] = arr[self.parent_id(t)]
				arr[self.parent_id(t)] = temp
				t = self.parent_id(t)
		return arr

	def getLeastNumbers(self, arr, k):
		"""
		:type arr: List[int]
		:type k: int
		:rtype: List[int]
		"""
	# 先从arr数组中取k个数，形成顶堆(k个元素)；
		sor_arr = self.get_item(arr,k)
		for i in range(k,len(arr)):
			#先判断顶堆的第一父节点 , 因此本题是取最小的，所有比父节点小的进行替换
			if sor_arr[0] < arr[i]:
				continue
			temp = arr[i]
			arr[i] = sor_arr[0]
			sor_arr[0] = temp
			t=0
			#要进行替换之前，必须要判断 该子节点的下标是否在维护k 顶堆的范围内
			while (self.rigth_id(t) < k and sor_arr[self.rigth_id(t)] > sor_arr[t] )or (self.lef_id(t) < k and sor_arr[self.lef_id(t)] > sor_arr[t]):
				#然后判断左节点大还是右节点大，然后把最大的进行替换
				if self.rigth_id(t) <k and sor_arr[self.rigth_id(t)] > sor_arr[self.lef_id(t)]:
					tem_rigth =  sor_arr[self.rigth_id(t)]
					sor_arr[self.rigth_id(t)] = sor_arr[t]
					sor_arr[t] = tem_rigth
					t = self.rigth_id(t)

				else:
					tem_lef = arr[self.lef_id(t)]
					sor_arr[self.lef_id(t)] = sor_arr[t]
					sor_arr[t] = tem_lef
					t = self.lef_id(t)
		return arr[:k]

```