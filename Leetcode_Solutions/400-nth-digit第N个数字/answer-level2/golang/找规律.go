### 规律

| 位数 | 范围       | 数位 | 个数           | 总的个数 |
| ---- | ---------- | ---- | -------------- | -------- |
| 1    | 0~9        | 1    | 9x1=9          | 9        |
| 2    | 10~99      | 10   | 9x10x2 =180    | 189      |
| 3    | 100~999    | 100  | 9x100x3 =2700  | 2889     |
| 4    | 1000～9999 | 1000 | 9x1000x4=36000 | 38700    |


### 代码
```
func findNthDigit(n int) int {
	var (
		num, digit = 1, 1
	)
	for n-num*digit*9 > 0 {
		n -= num * digit * 9
		num = num * 10
		digit = digit + 1
	}

	div, mod := (n-1)/digit, (n-1)%digit
	curNum := num + div

	var numList []int
	for ; curNum > 0; curNum /= 10 {
		numList = append(numList, curNum%10)
	}
	return numList[len(numList)-1-mod]
}
```