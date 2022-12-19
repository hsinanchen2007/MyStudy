树的题目，我们肯定要用树的方法解

第一遍dfs：计算root的总数，和所有节点对应的子节点树和本身的和

第二遍dfs：通过root再依次计算其他节点的路径
```
func sumOfDistancesInTree(N int, edges [][]int) []int {
	count := make([]int, N)
	sum := make([]int, N)
	m := make(map[int][]int)
	for i := 0; i < N; i++ {
		count[i] = 1
	}
	for i := 0; i < len(edges); i++ {
		m[edges[i][0]] = append(m[edges[i][0]], edges[i][1])
		m[edges[i][1]] = append(m[edges[i][1]], edges[i][0])
	}
	dfsRoot(0, -1, count, sum, m)
	dfsAll(0, -1, count, sum, m, N)
	return sum
}

func dfsRoot(now, root int, count, sum []int, m map[int][]int) {
	for _, n := range m[now] {
		if n == root {
			continue
		}
		dfsRoot(n, now, count, sum, m)
		count[now] += count[n]
		sum[now] += sum[n] + count[n]
	}
}

func dfsAll(now, root int, count, sum []int, m map[int][]int, N int) {
	for _, n := range m[now] {
		if n == root {
			continue
		}
		sum[n] = sum[now] - count[n] + N - count[n]
		dfsAll(n, now, count, sum, m, N)
	}
}

```
