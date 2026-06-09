```go
func findContentChildren(g []int, s []int) int {
	sort.Ints(g)
	sort.Ints(s)
	count := 0
	for {
		if len(s) == 0 || len(g) == 0 {
			break
		}
		cook := s[0]
		child := g[0]
		if cook >= child {
			s = s[1:]
			g = g[1:]
			count++
		} else {
			s = s[1:]
		}
	}
	return count
}
```
