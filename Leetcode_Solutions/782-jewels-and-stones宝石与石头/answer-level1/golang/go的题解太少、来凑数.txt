### 解题思路
此处撰写解题思路

### 代码

```golang
func numJewelsInStones(J string, S string) int {
    set := make(map[byte]bool)
	count := 0
	for _, j := range J {
		set[byte(j)] = true
	}
	for _, s := range S {
		if set[byte(s)]{
			count++
		}
	}
	return count
}
```