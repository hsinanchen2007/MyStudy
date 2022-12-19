def singleNumber(nums: List[int]) -> int:
	nums_set = set(nums)
	sum_num = sum(nums)
	div = sum_num - sum(nums_set)
	return sum_num - div // 2 * 3





def singleNumber1(nums: List[int]) -> int:
	bit_count = [0] * 32
	for num in nums:
		# 补全32位补码表示
		bin_num = (bin(((1 << 32) - 1) & num)[2:]).zfill(32)
		for index, s in enumerate(bin_num):
			if s == '1':
				bit_count[index] += 1
	s = ''
	for bit in bit_count:
		s += str(bit % 3)

	# 补码转为整型
	return int(s[1:], 2) - int(s[0]) * (1 << 31)