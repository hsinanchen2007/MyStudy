### 解题思路
两数之和加上两数之差的绝对值除以2等于最大值

### 代码

```golang
func maximum(a int, b int) int {
	return (a + b + int(math.Abs(float64(a-b)))) / 2
}
```