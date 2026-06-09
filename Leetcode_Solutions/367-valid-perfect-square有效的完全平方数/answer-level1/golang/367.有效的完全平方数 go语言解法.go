### 解题思路

从1开始遍历，到num/2为止，如果有i*i=num返回true，如果已经大于了num，返回true。

### 代码

```golang
func isPerfectSquare(num int) bool {
	if num == 1 {
		return true
	} 
	for i := 1;i <= num / 2;i++ {
		if i * i == num {
			return true
		}
		if i * i > num {
			break
		}
	}
	return false
}
```