### 解题思路
此处撰写解题思路

### 代码

```golang
// and：算是否进位，xor：计算加法结果（半加，即不带进位的加法）
func addBinary(a string, b string) string {
    var (
		sum, canary uint8
		buf         bytes.Buffer
	)

    if len(a) > len(b) {
		buf.Grow(len(a) + 1)
	} else {
		buf.Grow(len(b) + 1)
	}

	i, j := len(a)-1, len(b)-1
	for ; i >= 0 && j >= 0; i, j = i-1, j-1 {
		sum = canary + (a[i] - '0') + (b[j] - '0')
		switch sum {
		case 0:
			canary = 0
		case 1:
			canary = 0
		case 2:
			sum = 0
			canary = 1
		case 3:
			sum = 1
			canary = 1
		}
		buf.WriteByte(sum + '0')
	}

	for ; i >= 0; i-- {
		sum = (a[i] - '0') ^ canary
		canary &= a[i] - '0'
		buf.WriteByte(sum + '0')
	}

	for ; j >= 0; j-- {
		sum = (b[j] - '0') ^ canary
		canary &= b[j] - '0'
		buf.WriteByte(sum + '0')
	}

	if canary > 0 {
		buf.WriteByte(canary + '0')
	}

	ans := buf.Bytes()

	for k := 0; k < len(ans)/2; k++ {
		ans[k], ans[len(ans)-k-1] = ans[len(ans)-k-1], ans[k]
	}

	return string(ans)
}
```