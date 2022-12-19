# 嵌套循环

```go
func numJewelsInStones(J string, S string) int {
	count := 0
	if len(J) == 0 || len(S) == 0 {
		return count
	}
	for _, s := range S {
		for _, c := range J {
			if c == s {
				count++
			}
		}
	}
	return count
}
```

# map实现set功能 学习自大佬[@guanpengchn](/u/guanpengchn)

- 首先对J进行遍历，将字符分别存到HashSet中，以便之后遍历S的时候查找

- 遍历S，并将每个字符与HashSet中的进行比对，如果存在，则结果ans++，遍历结束，返回ans

- 时间复杂度：O(m+n)，m为J的长度，n为S的长度

```go
func numJewelsInStones(J string, S string) int {
	count := 0
	mark := map[rune]bool{}
	for _, c := range J {
		mark[c] = true
	}
	for _, s := range S {
		if mark[s] {
			count++
		}
	}
	return count
}
```