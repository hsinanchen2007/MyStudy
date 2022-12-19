1. 整理顶点
2. 整理边
3. 按照字典序排序顶点
4. 遍历所有顶点，dfs
5. 组装结果
![图片.png](https://pic.leetcode-cn.com/ca1cff3b264c0b93743457719eb356707ca54c9159b8f7531dba90aa9f7fde95-%E5%9B%BE%E7%89%87.png)

```
func trulyMostPopular(names []string, synonyms []string) []string {
	vertex := make(map[string]int)
	for _, info := range names {
		fields := strings.FieldsFunc(info, func(r rune) bool {
			return r == '(' || r == ')'
		})

		name := fields[0]
		count, err := strconv.Atoi(fields[1])
		if err != nil {
			fmt.Println(err)
			continue
		}
		vertex[name] = count
	}

	connectedVertex := make(map[string]struct{})
	
	edge := make([][]string, 0)
	for _, info := range synonyms {
		fields := strings.FieldsFunc(info, func(r rune) bool {
			return r == '(' || r == ',' || r == ')'
		})
		edge = append(edge, fields)
		connectedVertex[fields[0]] = struct{}{}
		connectedVertex[fields[1]] = struct{}{}
	}

	vertexVisited := make(map[string]bool, 0)

	var dfs func(root string, node string)
	dfs = func(root string, node string) {
		if visited, ok := vertexVisited[node]; ok && visited {
			return
		}

		vertexVisited[node] = true
		if root != node {
			vertex[root] += vertex[node]
		}

		for _, pair := range edge {
			if pair[0] == node {
				dfs(root, pair[1])
			} else if pair[1] == node {
				dfs(root, pair[0])
			} else {
				continue
			}
		}
	}

	namesInDictOrder := make([]string, 0)
	for name := range vertex {
		namesInDictOrder = append(namesInDictOrder, name)
	}
	sort.Strings(namesInDictOrder)

	result := make([]string, 0)
	for _, name := range namesInDictOrder {
		if visited, ok := vertexVisited[name]; ok && visited {
			continue
		}
		if _, ok := connectedVertex[name]; ok {
			dfs(name, name)
		}
		result = append(result, name + "(" + strconv.Itoa(vertex[name]) + ")")
	}

	return result
}
```
