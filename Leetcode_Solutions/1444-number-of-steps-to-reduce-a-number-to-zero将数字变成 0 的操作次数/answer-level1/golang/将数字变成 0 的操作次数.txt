### 解题思路
太简单，直接看代码吧

### 代码

```golang
func numberOfSteps(num int) int {
	step := 0
	for num != 0 {
		if num%2 == 0 {
			num /= 2
		} else {
			num--
		}
		step++
	}
	return step
}
```