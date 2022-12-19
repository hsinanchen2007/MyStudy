func addStrings(num1 string, num2 string) string {
	if num1 == "0"{
		return num2
	}

	if num2 == "0"{
		return num1
	}

	var indexOfNum1 = len(num1) - 1 //2
	var indexOfNum2 = len(num2) - 1 //1

	var resultArr []string
	var flagOfCarry = 0

	for indexOfNum1 >= 0 || indexOfNum2 >= 0{
		var tmpResult int

		var numberOf1 = 0
		var numberOf2 = 0
		//int转string
		if indexOfNum1 >= 0{
			number1OfInt, err := strconv.Atoi(string(num1[indexOfNum1]))
			if err != nil{
				return ""
			}

			numberOf1 = number1OfInt
		}else {
			numberOf1 = 0
		}

		if indexOfNum2 >= 0{
			number2OfInt, err := strconv.Atoi(string(num2[indexOfNum2]))
			if err != nil{
				return ""
			}

			numberOf2 = number2OfInt
		}else {
			numberOf2 = 0
		}

		tmpResult = numberOf1 + numberOf2 + flagOfCarry

		flagOfCarry = tmpResult / 10

		//string转int
		resultArr = append(resultArr, strconv.Itoa(tmpResult % 10))

		indexOfNum1--
		indexOfNum2--
	}

	if flagOfCarry == 1{
		resultArr = append(resultArr, "1")
	}

	//反转数组
	reverseArray(resultArr)

	var result string
	for i := 0; i < len(resultArr); i++{
		result += resultArr[i]
	}

	return result
}

func reverseArray(tmpSlice []string)  {
	var start = 0
	var end = len(tmpSlice) - 1
	for i := 0; i < len(tmpSlice) / 2; i++{
		tmpSlice[start], tmpSlice[end] = tmpSlice[end], tmpSlice[start]
		start++
		end--
	}
}