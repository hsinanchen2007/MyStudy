```
func compress(chars []byte) int {

	cLen := len(chars)

	if cLen == 0 || cLen == 1 {
		return cLen
	}

	read, fp, fpTime := 0, 0, 0

	b := chars[0:0]

	for read <= cLen-1 {

		if read+1 == cLen || chars[read] != chars[read+1] {
			b = append(b, chars[fp:fp+1]...)
			if fpTime > 1 {
				b = append(b, []byte(strconv.Itoa(fpTime))...)
			}
			fp = read + 1
			fpTime = 0
		} else {
			if fpTime == 0 {
				fp = read
				fpTime = 2
			} else {
				fpTime++
			}
		}
		read++
	}

	return len(b)
}

```
