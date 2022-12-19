	sum_A = sum(A)
	size = len(A)
	if sum_A % 3 != 0:
		return False
	sum_split = sum_A // 3
	temp, i = 0, 0
	while i < size and temp != sum_split:
		temp += A[i]
		i += 1
	if i > size - 2:
		return False
	else:
		temp, j = 0, size - 1
		while j > i and temp != sum_split:
			temp += A[j]
			j -= 1
		if temp != sum_split:
			return False
		else:
			return sum(A[i:j + 1]) == sum_split