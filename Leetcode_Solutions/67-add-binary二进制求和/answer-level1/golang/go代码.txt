func addBinary(a string, b string) string {
    strByteA := []byte(a)
	strByteB := []byte(b)

	var carry = byte(0)
	var result string

	curIndexA := len(strByteA) - 1
	curIndexB := len(strByteB) - 1

	for curIndexA >= 0 || curIndexB >= 0 || carry != 0 {

		var valA, valB = byte(0), byte(0)

		if curIndexA >= 0 {
			valA = strByteA[curIndexA] - 0x30
			curIndexA--
		}

		if curIndexB >= 0 {
			valB = strByteB[curIndexB] - 0x30
			curIndexB--
		}

		total := valA + valB + carry

		carry = total / 2
		total = total % 2

		result = strconv.Itoa(int(total)) + result
	}

	return result
}