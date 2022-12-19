func convert(s string, numRows int) string {
	if numRows == 1 {
		return  s
	}
	m := make([]string,numRows)
	lens := len(s)
	j := 0
	zh := true
	for i := 0; i < lens; i++ {

		m[j] = m[j] + s[i:i+1]
		if zh {
			j++
			if j == numRows {
				j = numRows - 2
				zh = false
			}
		} else {
			j--
			if j == -1 {
				j = 1
				zh = true
			}
		}
	}

	ret := ""
	for _,val := range m {
		ret = ret + val
	}
	return ret
}