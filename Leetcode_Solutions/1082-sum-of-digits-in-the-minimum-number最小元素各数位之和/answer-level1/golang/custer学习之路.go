第一思路代码：

```go
func sumOfDigits(A []int) int {
	// 1.遍历数组取得最小值
	min := 1<<31 - 1
	for _, v := range A {
		if v < min {
			min = v
		}
	}
	fmt.Println("min: ", min)
	// 2.最小值的各个位数之和
	sum := 0
	s := strconv.Itoa(min) // 最小数转换成字符串
	fmt.Println("min转换成字符串: ", s)

	for _, c := range s {
		tmp, err := strconv.Atoi(string(c))
		if err != nil {
			return 0
		}
		sum = sum + tmp
		fmt.Println("sum: ", sum)
	}
	// 3.判断奇偶数
	if sum%2 == 0 {
		return 1
	} else {
		return 0
	}
}
```

参考学习[@大佬的代码](https://leetcode-cn.com/u/resara)，简化代码

```go
func sumOfDigits(A []int) int {
	min := A[0]
	for i := 1; i < len(A); i++ {
		if A[i] < min {
			min = A[i]
		}
	}
	t := 0
	for min > 0 {
		t += min % 10
		min /= 10
	}
	if t%2 == 0 {
		return 1
	}
	return 0
}
```