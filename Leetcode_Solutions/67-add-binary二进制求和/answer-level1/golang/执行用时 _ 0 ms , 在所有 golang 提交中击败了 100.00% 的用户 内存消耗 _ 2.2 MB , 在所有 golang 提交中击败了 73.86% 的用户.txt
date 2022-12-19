```
func addBinary(a string, b string) string {
	bytesA, bytesB := []byte(a), []byte(b)
	lenA, lenB := len(bytesA), len(bytesB)
	// 输出bytes长度(比最长的bytes长度大一，因为最高位可能进位)
	var outLen int

	// 将两个数组标准化成等长
	// 举例：[]byte("11111")和[]byte("1")
	// 转化后：[]byte("11111")和[]byte("000001")
	var standardBytesA, standardBytesB []byte
	if lenA != lenB {
		// 两个数组不等长
		if lenA < lenB {
			standardBytesB = bytesB
			standardBytesA = make([]byte, lenB)
			for i, j := lenA-1, lenB-1; j >= 0; j -- {
				if i >= 0 {
					standardBytesA[j] = bytesA[i]
					i--
				} else {
					standardBytesA[j] = '0'
				}
			}

			outLen = lenB + 1
		} else {
			standardBytesA = bytesA
			standardBytesB = make([]byte, lenA)
			for i, j := lenB-1, lenA-1; j >= 0; j -- {
				if i >= 0 {
					standardBytesB[j] = bytesB[i]
					i--
				} else {
					standardBytesB[j] = '0'
				}
			}
			outLen = lenA + 1
		}
	} else {
		// 两个数组等长
		standardBytesA, standardBytesB = bytesA, bytesB
		outLen = lenA + 1
	}
	// 存结果的byte数组
	outBytes := make([]byte, outLen)
	var carrybit bool
	// outLen - 2:standardX的最后index
	for i := outLen - 2; i >= 0; i-- {
		// 从standardX的最低位开始计算
		outBytes[i+1] = bitAdd(standardBytesA[i], standardBytesB[i], &carrybit)
	}

	// 最后判断最高位是否有进位
	if carrybit {
		//进位
		outBytes[0] = '1'
		return string(outBytes)
	} else {
		return string(outBytes[1:])
	}
}

func bitAdd(b1, b2 byte, carryBit *bool) (ret byte) {
	// 如果上一次有进位
	if *carryBit {
		// '0'+'0'=96
		if b1+b2 == 96 {
			ret = '1'
			*carryBit = false
		} else if b1+b2 == 97 {
			// '0'+'1'=97
			ret = '0'
		} else {
			// '1'+'1'=98
			ret = '1'
		}

	} else {
		// '0'+'0'=96
		if b1+b2 == 96 {
			ret = '0'
		} else if b1+b2 == 97 {
			// '0'+'1'=97
			ret = '1'
		} else {
			// '1'+'1'=98
			ret = '0'
			*carryBit = true
		}

	}

	return
}

```


![image.png](https://pic.leetcode-cn.com/a4a915c60e3460ea4cfdd75fde536c7934006992feba420a031f4f7fee5e71bc-image.png)
