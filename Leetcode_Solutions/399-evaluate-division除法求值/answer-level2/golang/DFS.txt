```
type edge struct {
	From  string
	To    string
	Value float64
}

func calcEquation(equations [][]string, values []float64, queries [][]string) (rst []float64) {
	var (
		i       int
		query   []string
		length  = len(equations)
		visited = map[string]bool{}
		graph   = map[string][]edge{}
	)

	rst = make([]float64, len(queries))
	for i = 0; i < length; i++ {
		graph[equations[i][0]] = append(graph[equations[i][0]], edge{
			From:  equations[i][0],
			To:    equations[i][1],
			Value: values[i],
		})
		graph[equations[i][1]] = append(graph[equations[i][1]], edge{
			From:  equations[i][1],
			To:    equations[i][0],
			Value: 1.0 / values[i],
		})
	}

	for i = 0; i < len(queries); i++ {
		query = queries[i]
		if len(graph[query[0]]) == 0 || len(graph[query[1]]) == 0 {
			rst[i] = -1.0
			continue
		} else if query[0] == query[1] {
			rst[i] = 1
			continue
		}
		visited = map[string]bool{}
		rst[i] = dfs(query, graph, visited)
		if rst[i] == 0 {
			rst[i] = -1
		}
	}
	return
}

func dfs(query []string, graph map[string][]edge, visited map[string]bool) float64 {
	for i := 0; i < len(graph[query[0]]); i++ {
		curr := graph[query[0]][i]
		if visited[curr.To] {
			continue
		}
		if curr.To == query[1] {
			return curr.Value
		}
		visited[curr.To] = true
		if value := dfs([]string{curr.To, query[1]}, graph, visited); value != 0 {
			return value * curr.Value
		}
		visited[curr.To] = false
	}
	return 0
}

```
