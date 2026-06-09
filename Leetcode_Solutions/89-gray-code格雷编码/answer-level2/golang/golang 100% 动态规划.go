### 解题思路
动态规划：每增加一个高位：等于高位数 + 之前数组的倒序
例如： 前两位0，1，3，2：第三位就是4+2， 4+3， 4+1， 4+0。依次类推
### 代码

```golang
// 二进制处理
func grayCode(n int) []int {
	if n == 0 {
		return []int{0}
	}
	size := int(math.Exp2(float64(n)))
	data := make([]int, size)
	data[0] = 0
	base := 1

	for digit := 0; digit < n; digit++ { // 控制位数
		for i := 0; i < base; i++ { // 每增加一位,前面所有的数高位+1 反向
			data[base+i] = data[base-i-1] + base
		}
		base *= 2
	}
	return data
}

```