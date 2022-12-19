class Solution:
	def duplicateZeros(self, arr) -> None:
		"""
		Do not return anything, modify arr in-place instead.
		"""
		for i in range(len(arr)-2,-1,-1):
			if arr[i]==0:
				arr.insert(i+1,0)
				arr.pop()
执行用时 :88 ms, 在所有 Python3 提交中击败了76.83%的用户
内存消耗 :14.4 MB, 在所有 Python3 提交中击败了100.00%的用户