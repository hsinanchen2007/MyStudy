```
func convert(s string, numRows int) string {
	s_byte := []byte(s)
	if len(s_byte) <= numRows || numRows ==1 {
		return s
	}

	m := 1
	lenth := len(s_byte)
	res_group := make(map[int][]byte)
	key := numRows
	for i := 1; i <= lenth; i++ {

		if len(s_byte) == 0 {
			break
		}
		if i == 1 || i == m {
			m = i + numRows - 1
			key = numRows
			s_byte_lenth := len(s_byte)

			if s_byte_lenth < numRows {
				res_group[i] = s_byte[0:s_byte_lenth]

				s_byte = s_byte[s_byte_lenth:]
				break

			} else {
				res_group[i] = s_byte[0:numRows]
				s_byte = s_byte[numRows:]
			}

		} else {
			key = key - 1
			tmp := []byte{}
			for j := 1; j <= numRows; j++ {
				if j == key {
					tmp = append(tmp, s_byte[0:1][0])
				} else {
					tmp = append(tmp, 0)
				}
			}
			res_group[i] = tmp
			s_byte = s_byte[1:]
		}
	}

	var result_group [][]byte
	for_lenth := 0
	for i := 1; i <= len(res_group); i++ {
		tmp := res_group[i]
		result_group = append(result_group, tmp)
		if i == 1 {
			for_lenth = len(tmp)
		}
	}

	var result []byte
	for i := 0; i < for_lenth; i++ {
		for j := 0; j < len(result_group); j++ {
				if i+1 <= len(result_group[j]) && result_group[j][i] != 0 {
				result = append(result, result_group[j][i])
			}
		}
	}
	// fmt.Println(result)
		return string(result[:])
}

```