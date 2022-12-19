### 解题思路
此处撰写解题思路
起点为 1-9
下一位 满足条件 差值为K  就接入 长度-1 继续dfs
### 代码

```golang
func numsSameConsecDiff(N int, K int) []int {
	if N == 1 {
		return []int{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
	}
	ans := make([]int, 0)
	for i := 1; i <= 9; i++ {
		dfs(i, N, K, i, &ans)
	}
	return ans
}
func dfs(node, len, k, re int, ans *[]int) {
	if len == 1 {
		*ans = append(*ans, re)
		return
	}
	next := node + k
	if 0 <= next && next <= 9 && k != 0 {
		re = re*10 + next
		dfs(next, len-1, k, re, ans)
		re = (re - next) / 10
	}
	next = node - k
	if 0 <= next && next <= 9 {
		re = re*10 + next
		dfs(next, len-1, k, re, ans)
		re = (re - next) / 10
	}
}
```