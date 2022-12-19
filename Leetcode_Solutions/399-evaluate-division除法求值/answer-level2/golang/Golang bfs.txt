### 解题思路
此处撰写解题思路

### 代码

```golang
import "fmt"

type node struct {
    char string
    value float64
}

func calcEquation(equations [][]string, values []float64, queries [][]string) []float64 {
    graph := map[string]map[string]float64{}
    result := []float64{}
    
    for i, pair := range equations {
        baseChar := pair[0]
        baseValue := values[i]
        subChar := pair[1]
        subValue := 1 / values[i]
        if _, ok := graph[baseChar]; !ok {
            graph[baseChar] = make(map[string]float64)
        }
        if _, ok := graph[subChar]; !ok {
            graph[subChar] = make(map[string]float64)
        }
        graph[baseChar][subChar] = baseValue
        graph[subChar][baseChar] = subValue
    }

    for ind, pair := range queries {
        startChar := pair[0]
        targetChar := pair[1]
        visited := map[string]bool{}
        underSearch := []node{}
        underSearch = append(underSearch, node{char:startChar, value: 1})
        for len(underSearch) > 0 {
            searchingChar := underSearch[0].char
            searchingValue := underSearch[0].value
            underSearch = underSearch[1:]
            if _, ok := graph[searchingChar]; !ok {
                continue
            }
            for k, v := range graph[searchingChar] {
                if _, ok := visited[k]; ok {
                    continue
                }
                if k == targetChar {
                    result = append(result, searchingValue*v)
                    underSearch = []node{}
                    break
                }
                visited[k] = true
                underSearch = append(underSearch, node{char: k, value: searchingValue*v})
            }
        }
        if len(result) == ind {
            result = append(result, -1)
        }
    }
    
    return result
}
```