```python
class Solution:
	def maxTurbulenceSize(self, A: List[int]) -> int:
		
		# window condition: 
		# [0 8 45 88 48 68 28 55 17 24]
		#   < <  <  >  <  >  <  >  <

		# Time complexity: O(N)
		# Space complexity: O(1)
		
		res, j, flag = 1, 0, 0
		for i in range(1, len(A)):
			if flag == 0: # restart counting
				res = max(res, i  -  j)
				if A[i] > A[i - 1]: flag = 1 # > < > 
				elif A[i] < A[i - 1]: flag = 2 # < > <
				else: j = i   # continue
			elif A[i] == A[i - 1]: # stop condition
				res = max(res, i  -  j)
				flag = 0
				j = i
			elif (flag == 1 and A[i] > A[i - 1] ) or (flag == 2 and A[i] < A[i - 1]): # stop condition
				res = max(res, i  -  j)
				flag = 1 if A[i] > A[i - 1] else 2
				j = i - 1
			else:  # go on
				flag = 1 if flag == 2 else 2
				res = max(res, i  + 1 -  j)
		return  res
```