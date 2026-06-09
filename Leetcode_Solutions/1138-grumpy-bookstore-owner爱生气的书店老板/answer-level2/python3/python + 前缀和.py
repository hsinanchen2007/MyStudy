```python
class Solution:
	def maxSatisfied(self, customers: List[int], grumpy: List[int], X:int) -> int:
		# use sum_prefix

		# Time complexity: O(N)
		# Space complexity: O(N)

		# customers = [1, 0, 1, 2, 1, 1, 7, 5]
		# grumpy =    [0, 1, 0, 1, 0, 1, 0, 1]
		# no_angry = [0, 1, 1, 2, 4, 5, 6, 13, 18]
		# angry = 	[0, 1, 1, 1, 1, 2, 2, 9, 0]
		# window size = 3

		l = len(customers)
		no_angry= [0] * (l+ 1)
		angry = [0] * (l + 1)
		for i in range(l):
			no_angry[i + 1] = no_angry[i] + customers[i]
			angry[i + 1] = angry[i] + customers[i] * (1 - grumpy[i]) 
		res = 0
		for i in range(X, l + 1):
			val = no_angry[i] - no_angry[i - X] + angry[i - X] + (angry[l] - angry[i])
			res = max(res, val)
		return res
```