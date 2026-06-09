### 解题思路
动态规划的优化，用a来记录dp[i-2],b记录dp[i-1]

### 代码

```golang
func massage(nums []int) int {
	a := 0
	b := 0
    var c int
	for _,v := range nums {
		c = a +v
		if b > c {
			c = b
		}
		a = b
		b = c
	}
    return c
}
```