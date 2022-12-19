	s_list = []
	temp_str = ""
	count = 0
	for s in S:
		if s == "(":
			count += 1
		elif s == ")":
			count -= 1
		temp_str += s
		if count == 0:
			s_list.append(temp_str[1:-1])
			temp_str = ""
	return ''.join(s_list)