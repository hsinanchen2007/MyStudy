### 解题思路

排除掉0和负数后，n如果是2的幂次，则n % 2,4,8,16...都等于0，所以可以从2开始取余，若对小于等于n的每个2的幂次取余都得0，则返回true，否则false

### 代码

```golang
func isPowerOfTwo(n int) bool {
    if n <= 0 {
		return false
	}
	var i int = 0
	for {
		m := int(math.Pow(float64(2),float64(i)))
		if m > n {
			return true
		}
		if n % m != 0 {
			return false
		}
		i++
	}
}
```