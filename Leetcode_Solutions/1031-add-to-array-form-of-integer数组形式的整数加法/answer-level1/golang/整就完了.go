### 解题思路
此处撰写解题思路

### 代码

```golang
func addToArrayForm(A []int, K int) []int {

	var str1 string
    var str2 string

    for i := 0; i < len(A); i++ {
        str1 += strconv.Itoa(A[i])
    }

    str2 = strconv.Itoa(K)

	return addStr(str1, str2)
}

func addStr(a, b string) []int {
	lena := len(a)
	lenb := len(b)
    fmt.Println(lena, lenb)
	if len(a) < len(b) {
		return addStr(b, a)
	}

	tmp := 0
	tmpa := 0
	tmpb := 0
	carry := 0 //进位
	var numSlice []int
	for i := lena - 1; i >= 0; i-- {

		if lenb == 0 {
			tmpa, _ = strconv.Atoi(string(a[i]))
			tmp = tmpa + carry
			carry = tmp / 10
			tmp = tmp % 10
			numSlice = append(numSlice, tmp)
            continue
		}

		lenb--
		tmpa, _ = strconv.Atoi(string(a[i]))
		tmpb, _ = strconv.Atoi(string(b[lenb]))
		tmp = tmpa + tmpb + carry
		//进位
		carry = tmp / 10
		//最终值
		tmp = tmp % 10
		//切片是倒序的 别忘了反转
		numSlice = append(numSlice, tmp)
	}
	if carry == 1 {
		numSlice = append(numSlice, 1)
	}
	//反转
	var resSlice []int
	for i := len(numSlice) - 1; i >= 0; i-- {
		resSlice = append(resSlice, numSlice[i])
	}
	return resSlice
}
```