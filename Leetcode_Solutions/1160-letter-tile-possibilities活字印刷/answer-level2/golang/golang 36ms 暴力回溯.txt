因为数据量很小，所以直接暴力回溯解决问题，并用map去重。

优化：可以对tiles排序，回溯时如果和上一个相同，就不用遍历当前。
```
func numTilePossibilities(tiles string) int {
	used := make([]bool, len(tiles))
	m := make(map[string]struct{})
	backtrack("", used, tiles, m)
	return len(m)
}

func backtrack(now string, used []bool, str string, m map[string]struct{}) {
	if len(now) > 0 {
		m[now] = struct{}{}
	}
	if len(now) == len(str) {
		return
	}
	for i := 0; i < len(str); i++ {
		if used[i] {
			continue
		}
		used[i] = true
		backtrack(now + string(str[i]), used, str, m)
		used[i] = false
	}
}

```