### 解题思路
此处撰写解题思路
1、拆分数字 123=> 1²+2²+3²（和reverse Number 方法相同）
2、如果 ²和已经出现过 则说明这个数值 不是快乐数 => false
3、注意数值的溢出 若²和超出32位 也为=>false
### 代码

```golang
func isHappy(n int) bool {
isExist := make(map[int]bool)
	if n == 1 {
		return true
	}

	for n != 1 {
		num := 0
		// 19=> 1²+9²
		for n != 0 {
			num += (n%10)*(n%10)
			n /= 10
		}
		n = num
		if isExist[n] {
			return false
		} else {
			isExist[n] = true
		}

		if n < -1<<32 || n > 1<<32-1 {
			return false
		}
	}

	return true
}
```