### 解题思路

简单但不是最快的递归做法

### 代码

```golang
func addDigits(num int) int {
	sum := 0
	for num != 0 {
		sum += num % 10
		num /= 10
	}
	if sum / 10 == 0{
		return sum
	}else {
		return addDigits(sum)
	}
}
```