### 解题思路
最小栈

### 代码

```golang
type RepMin struct {
	val int
	cnt int
}

const MOD int = 1000000007

func sumSubarrayMins(A []int) int {
	stack := make([]RepMin, 0)
	sum := 0
	dot := 0
	for _, v := range A {
		count := 1
		for len(stack) > 0 && stack[len(stack)-1].val >= v {
			rm := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			count += rm.cnt
			dot -= rm.val * rm.cnt
		}
		dot += v * count
		sum += dot
		sum %= MOD
		stack = append(stack, RepMin{
			val: v,
			cnt: count,
		})
	}
	return sum
}
```