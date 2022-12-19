```
 func addBinary(a string, b string) string {
	ret := ""
	res := []int{}
	counta := len(a) - 1
	countb := len(b) - 1
	add := 0 // 如果和为2 则将下一位需要加1 原值为0

	// 从后往前 想加 将值放入res中
	// 遇2进1
	for counta >= 0 && countb >= 0 {
		total := StrAdd(string(a[counta]), string(b[countb]))
		if total == 2 {
			res = append(res, 0+add)
			add = 1
		} else {
			if total+add == 2 {
				add = 1
				res = append(res, 0)
			} else {
				res = append(res, total+add)
				add = 0
			}
		}
		counta--
		countb--
	}
	// 处理未相加的数
	if counta != -1 {
		for counta >= 0 {
			inta, _ := strconv.Atoi(string(a[counta]))
			if inta+add == 2 {
				res = append(res, 0)
				add = 1
			} else {
				res = append(res, inta+add)
				add = 0
			}
			counta--
		}
	}

	if countb != -1 {
		for countb >= 0 {
			intb, _ := strconv.Atoi(string(b[countb]))
			if intb+add == 2 {
				res = append(res, 0)
				add = 1
			} else {
				res = append(res, intb+add)
				add = 0
			}
			countb--
		}
	}
	// 处理最后一位 如果为1则需要要将这个数加上
	if add == 1 {
		res = append(res, add)
	}
	// 反转得到的数组 转换为字段串
	for i := 0; i <= len(res)-1; i++ {
		tmps := strconv.Itoa(res[i])
		ret = tmps + ret
	}

	return ret
}

func StrAdd(i, j string) (total int) {
	inti, _ := strconv.Atoi(i)
	intj, _ := strconv.Atoi(j)
	return inti + intj
}
```