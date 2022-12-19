def addToArrayForm1(A: List[int], K: int) -> List[int]:
	result = []
	while K:
		K, m = divmod(K, 10)
		n = A.pop() if A else 0
		x, y = divmod(m + n, 10)
		K += x
		result.append(y)
	return A + result[::-1]