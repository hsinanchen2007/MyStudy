### 解题思路
so easy

### 代码

```golang
func findComplement(num int) int {
	ret := 0
	os := fmt.Sprintf("%b", num)
	n := len(os) - 1
	for _, v := range os {
		if v == '0' {
			ret += int(math.Pow(2, float64(n)) * 1)
		}
		n--
	}
	return ret
}
```