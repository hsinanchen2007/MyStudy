
def multiply(num1: str, num2: str) -> str:
	if num1 == '0' or num2 == '0':
		return '0'
	num1 = num1[::-1]
	num2 = num2[::-1]
	result = [0] * (len(num1) + len(num2))
	for index1, n1 in enumerate(num1):
		for index2, n2 in enumerate(num2):
			index = index1 + index2
			carry, res = divmod(int(n1) * int(n2) + result[index], 10)
			result[index] = res
			result[index + 1] += carry
	result = result[::-1]
	for i in range(len(result)):
		if result[i]:
			result = result[i:]
			break
	return ''.join([str(i) for i in result])