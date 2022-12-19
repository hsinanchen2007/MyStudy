
```
func isAdditiveNumber(num string) bool {
	res := make([]string,0, len(num))
	return dfs(res,0,num)
}

//index is the cur point
func dfs(res []string, index int, num string) bool {
	eles := len(res)

	if eles >= 3 && add(res[eles - 3], res[eles - 2]) != res[eles - 1] {
			return false
	}
	if index == len(num) {
		return eles >= 3
	}
	l, r := getNum3Bound(res, num, index)
	for bits := l; bits <= r && index + bits <= len(num); bits++ {
		res = append(res,num[index:index+bits])
		if dfs(res,index + bits, num){
			return  true
		}
		res = append(res[:len(res)-1])
	}
	return false
}

// a + b = c -> m = max(bit(a),bit(b)), bit(c) = [m, m+1]
//get bit limit of num3
func getNum3Bound(res []string, num string, index int) (l,r int) {
	if num[index] == "0"[0]{
		l, r = 1, 1
	}else if len(res) <= 1{
		l, r = 1, len(num) / 2
	}else{
		num1, num2 := res[len(res)-2],res[len(res)-1]
		if len(num1) >= len(num2){
			l, r = len(num1),len(num1) + 1
		}else{
			l, r = len(num2),len(num2) + 1
		}
	}
	return
}

func add(num1, num2 string) string {
	var extra uint8 = 0
	bits := 0
	var pre1 []string
	var pre2 []string
	if len(num1) >= len(num2){
		bits = len(num1)
	}else{
		bits = len(num2)
	}
	res := make([]string, bits, bits + 1)
	prefix := ""
	for i:=0; i < bits - len(num1); i++{
		pre1 = append(pre1,"0")
	}
	for i:=0; i < bits - len(num2); i++{
		pre2 = append(pre2,"0")
	}
	num1 = strings.Join(pre1,"") + num1
	num2 = strings.Join(pre2,"") + num2
	for i := bits - 1; i >= 0; i--{
		bit1 := num1[i] - "0"[0]
		bit2 := num2[i] - "0"[0]
		sum := bit1 + bit2 + extra
		res[i] = strconv.Itoa(int(sum % 10))
		extra = sum / 10
	}
	if extra == 1{
		prefix = "1"
	}
	return prefix + strings.Join(res,"")
}
```