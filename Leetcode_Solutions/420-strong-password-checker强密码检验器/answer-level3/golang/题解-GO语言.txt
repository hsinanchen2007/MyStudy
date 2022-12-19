小于6 :  直接比较缺失类型和缺失字符数量的大小，取最大的
6-20: 直接考虑替换，数值为 len/3
大于20：先用缺失类型替换，然后删除连续字符到20，再用替换解决。 因为替换和删除的数量级是：len/3 vs (len-1)，所以替换有限考虑 %3==2 的， 删除有限考虑 %3==0 的

```
func strongPasswordChecker(s string) int {
	// 统计字符类型
	missTypes := 3
	hasLowercase, hasUppercase, hasDigit := false, false, false
	sLen := len(s)
	for _, v := range s {
		if !hasLowercase && unicode.IsLower(v) {
			missTypes = missTypes - 1
			hasLowercase = true
		} else if !hasUppercase && unicode.IsUpper(v) {
			missTypes = missTypes - 1
			hasUppercase = true
		} else if !hasDigit && unicode.IsDigit(v) {
			missTypes = missTypes - 1
			hasDigit = true
		}
	}
	steps := 0

	// 长度小于6的时候，优先考虑插入，优先考虑补充类型
	if sLen < 6 {
		if 6 - sLen >= missTypes {
			return 6 - sLen
		}
		return missTypes
	} else if sLen > 20 {
		// 先使用缺失类型替换
		result := getSameCharArray(s)
		for{
			index := find(result, 2)
			if missTypes <=0 || index <= -1 {
				break
			}
			if result[index] - 3 > 0 {
				result[index] = result[index] - 3
			}else {
				result[index] = 0
			}
			steps++
			missTypes--
		}

		// 删除连续字符
		minDelete := sLen - 20
		for{
			index := find(result, 0)
			if minDelete <= 0 || index <= -1{
				steps += minDelete
				break
			}
			minDelete--
			steps++
			if result[index] - 3 > 0 {
				result[index] = result[index] - 1
			}else {
				result[index] = 0
			}
		}
		for _, v := range result {
			steps += v / 3
		}
		return steps + missTypes
	}
    // 6 - 20 直接考虑替换
	result := getSameCharArray(s)
	for _, v := range result {
		steps += v / 3
	}
	if steps < missTypes {
		return missTypes
	}
	return steps
}

func getSameCharArray(s string) (result []int){
	length := 0
	lastIndex := ""
	for index, v := range s{
		if string(v) != lastIndex{
			if length >= 3 {
				result = append(result, length)
			}
			lastIndex = string(v)
			length = 1
		} else if index == len(s)-1{
			length = length+1
			if length >= 3 {
				result = append(result, length)
			}
		}else{
			length = length + 1
		}
	}
	return result
}

func find(array []int, left int) int {
	n0, n1, n2 := -1, -1, -1
	for i := 0; i< len(array); i++ {
		if array[i] > 0 && array[i] % 3 == 0 {
			n0 = i
		}

		if array[i] > 0 && array[i] % 3 == 1 {
			n1 = i
		}

		if array[i] > 0 && array[i] % 3 == 2 {
			n2 = i
		}
	}

    // 0 > 1 > 2
	if left == 0 {
		if n0 > -1 {
			return n0
		} else if n1 > -1 {
			return n1
		} else {
			return n2
		}
	} else if left == 2 { // 2 > 1 > 0
		if n2 > -1 {
			return n2
		} else if n1 > -1 {
			return n1
		} else {
			return n0
		}
	}
	return -1
}
```
