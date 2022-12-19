### 解题思路
以0为中心对称分布

### 代码

```golang
func sumZero(n int) []int {
    pair := n / 2

	ans := make([]int, n)
	for i := 0; i < pair; i++ {
		ans[i] = i + 1
		ans[pair+i] = -(i + 1)
	}

	return ans
}
```