通过位运算将str压缩成数字，这一步比较简单。
`v += 1 << uint(arr[i][j]-'a')`

通过异或运算判断两个二进制数字是否有相同的位， 这一步比较简单。
`(b[i]^val) != (b[i]+val)`

最后就是简单的回溯，直接模版，这一步比较简单。
```
func backtrack() {
	if now > *max {
		*max = now
	}
	for i := idx; i < len(b); i++ {
		if visited[i] || (b[i]^val) != (b[i]+val) {
			continue
		}
		visited[i] = true
		backtrack()
		visited[i] = false
	}
}
```

所以这题比较简单。。。。。。
完整代码：
```Go
func maxLength(arr []string) int {
	var (
		max    int
		b, cnt []int
	)
	for i := 0; i < len(arr); i++ {
		v := 0
		for j := 0; j < len(arr[i]); j++ {
            if v == (v | 1<<uint(arr[i][j]-'a')) {
				v = -1
				break
			}
			v += 1 << uint(arr[i][j]-'a')
		}
		if v != -1 {
			b = append(b, v)
			cnt = append(cnt, len(arr[i]))
		}
	}
	backtrack(b, cnt, make([]bool, len(b)), 0, 0, 0, &max)
	return max
}

func backtrack(b, cnt []int, visited []bool, idx, val, now int, max *int) {
	if now > *max {
		*max = now
		if *max == 26 {
			return
		}
	}
	for i := idx; i < len(b); i++ {
		if visited[i] || (b[i]^val) != (b[i]+val) {
			continue
		}
		visited[i] = true
		backtrack(b, cnt, visited, i+1, val|b[i], now+cnt[i], max)
		visited[i] = false
	}
}

```
