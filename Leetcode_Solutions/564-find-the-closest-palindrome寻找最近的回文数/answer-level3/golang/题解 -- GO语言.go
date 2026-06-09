```

func nearestPalindromic(n string) string {
	nLen := len(n)
	nNum, _ := strconv.Atoi(n)
    // 一位数一般来说直接选择比自己小一的数，除非是0
	if nLen == 1 {
		if nNum - 1 >= 0 {
			return strconv.Itoa(nNum - 1)
		}
		return strconv.Itoa(nNum + 1)
	} else if nLen == 2 && n[0] == '1' { // 1x的数要判断是9还是22
		distance9 := abs(nNum - 9)
		distance11 := abs(nNum-11)
		distance22 := abs(nNum-22)
		if distance11 == 0 {
			if distance9 <= distance22 {
				return "9"
			}
			return "22"
		}
		if distance9 <= distance11 && distance9 <= distance22 {
			return "9"
		}else if distance11 <= distance9 && distance11 <= distance22 {
			return "11"
		}
		return "22"
	}
    // 找前半部分的数字
	highHalf := n[0:(nLen+1)/2]
	highHalfNums, _ := strconv.Atoi(highHalf)
	highHalfReduce1 := strconv.Itoa(highHalfNums - 1)
	highHalfPlus1 := strconv.Itoa(highHalfNums + 1)

    // 判断长度是奇数还是偶数，比较前半部分+1, -1, 不变情况下哪种回文数距离最近
	if nLen % 2 == 0 {
		originN, _ := strconv.Atoi(highHalf + reverse(highHalf))
		originSteps := abs(originN-nNum)

        // 判断是否为10x
		var reduceN int
		if len(highHalfReduce1) == len(highHalf) {
			reduceN, _ = strconv.Atoi(highHalfReduce1 + reverse(highHalfReduce1))
		} else {
			reduceN, _ = strconv.Atoi(highHalfReduce1 + "9" + reverse(highHalfReduce1))
		}
		reduceSteps := abs(reduceN-nNum)

        // 判断是否为9x
		var plusN int
		if len(highHalfPlus1) == len(highHalf) {
			plusN, _ = strconv.Atoi(highHalfPlus1 + reverse(highHalfPlus1))
		} else {
			plusN, _ = strconv.Atoi(highHalfPlus1 + reverse(highHalfPlus1)[1:len(highHalfPlus1)])
		}
		plusSteps := abs(plusN-nNum)

        // 选择最小的
		if strconv.Itoa(originN) == n {
			if reduceSteps <= plusSteps {
				return strconv.Itoa(reduceN)
			}
			return strconv.Itoa(plusN)
		}
		if reduceSteps <= originSteps && reduceSteps <= plusSteps {
			return strconv.Itoa(reduceN)
		} else if originSteps <= reduceSteps && originSteps <= plusSteps {
			return strconv.Itoa(originN)
		}
		return strconv.Itoa(plusN)
	} else {
		originN, _ := strconv.Atoi(highHalf + reverse(highHalf)[1:len(highHalf)])
		originSteps := abs(originN-nNum)

		var reduceN int
		if len(highHalfReduce1) == len(highHalf) {
			reduceN, _ = strconv.Atoi(highHalfReduce1 + reverse(highHalfReduce1)[1:len(highHalfReduce1)])
		} else {
			reduceN, _ = strconv.Atoi(highHalfReduce1 + reverse(highHalfReduce1))
		}
		reduceSteps := abs(reduceN-nNum)

		var plusN int
		if len(highHalfPlus1) == len(highHalf) {
			plusN, _ = strconv.Atoi(highHalfPlus1 + reverse(highHalfPlus1)[1:len(highHalfPlus1)])
		} else {
			plusN, _ = strconv.Atoi(highHalfPlus1 + reverse(highHalfPlus1)[2:len(highHalfPlus1)])
		}
		plusSteps := abs(plusN-nNum)

		if strconv.Itoa(originN) == n {
			if reduceSteps <= plusSteps {
				return strconv.Itoa(reduceN)
			}
			return strconv.Itoa(plusN)
		}
		if reduceSteps <= originSteps && reduceSteps <= plusSteps {
			return strconv.Itoa(reduceN)
		} else if originSteps <= reduceSteps && originSteps <= plusSteps {
			return strconv.Itoa(originN)
		}
		return strconv.Itoa(plusN)
	}
}

func abs(a int) int {
	if a > 0 {
		return a
	}
	return 0 - a
}

func reverse(n string) string {
	byteN := []byte(n)
	var reverseN  []byte
	for i := 0; i< len(byteN); i++{
		reverseN = append(reverseN, byteN[len(n)-i-1])
	}

	return string(reverseN)
}
```
