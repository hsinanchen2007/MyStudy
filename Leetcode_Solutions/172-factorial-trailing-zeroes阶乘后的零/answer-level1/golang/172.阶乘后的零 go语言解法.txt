### 解题思路
计算阶乘后面0的个数就是计算因数中有多少个5，所以计算5的个数即为5的个数

### 代码

```golang
func trailingZeroes(n int) int {
	if n < 5 {
		return 0
	}else {
		return n / 5 + trailingZeroes(n / 5)
	}
}
```