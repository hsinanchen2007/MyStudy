### 解题思路
此处撰写解题思路

### 代码

```golang
func sumDigits(x int) int {
	sumVal := 0
    for _, c := range strconv.Itoa(x) {
		sumVal += int(c - '0')
	}
	//fmt.Println(sumVal)
	return sumVal
}

func addDigits(num int) int {
	n := num
	for n >= 10 {
		n = sumDigits(n)
	}
	return n
}

```