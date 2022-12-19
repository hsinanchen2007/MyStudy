bfs：维护一个先进先出的队列，每次拿出来的都是最短步数
backtrack：每次从当前交换位置的后一个位置继续比较


bfs > backtrack
```
func kSimilarity(A string, B string) int {
	var a, b []byte
	for i := 0; i < len(A); i++ {
		if A[i] == B[i] {
			continue
		}
		a = append(a, A[i])
		b = append(b, B[i])
	}
	return bfs(a, b, make(map[string]bool))
	// return backtrack(0, a, b, make(map[string]int))
}

type Node struct {
	str  string
	step int
}

func bfs(A, B []byte, visited map[string]bool) int {
	queue := make([]Node, 0) // [2]int 0: A, 1: step
	queue = append(queue, Node{string(A), 0})
	visited[string(A)] = true
	start, end := 0, 0
	for start <= end {
		a, step := []byte(queue[start].str), queue[start].step
		if string(a) == string(B) {
			return step
		}
		start++

		i := 0
		for a[i] == B[i] {
			i++
		}

		for j := i + 1; j < len(a); j++ {
			if a[j] == B[i] {
				a[i], a[j] = a[j], a[i]
				if !visited[string(a)] {
					visited[string(a)] = true
					queue = append(queue, Node{string(a), step + 1})
					end++
				}
				a[i], a[j] = a[j], a[i]
			}
		}
	}
	return 0
}

func backtrack(idx int, A, B []byte, m map[string]int) int {
	kb := make([]byte, len(A))
	copy(kb, A)
	key := string(kb)
	if key == string(B) {
		return 0
	}
	if v, ok := m[key]; ok {
		return v
	}
	for A[idx] == B[idx] {
		idx++
	}
	min := 2 << 31
	for i := idx + 1; i < len(A); i++ {
		if A[i] == B[idx] {
			A[i], A[idx] = A[idx], A[i]
			ret := backtrack(idx+1, A, B, m) + 1
			if ret < min {
				min = ret
			}
			A[i], A[idx] = A[idx], A[i]
		}
	}
	m[key] = min
	return min
}

```
