### 解题思路
此处撰写解题思路

### 代码

```golang
func alienOrder(words []string) string {
	// 边列表
	edges := make([][]byte, 0, 4)
	// 所有点的度
	nodeMap := make(map[byte]int)

	l := len(words)
	if l > 0 {
		for i := 0; i < len(words[0]); i++ {
			_, ok := nodeMap[words[0][i]]
			if !ok {
				nodeMap[words[0][i]] = 0
			}
		}
	}

	for i := 1; i < l; i++ { // 遍历单词列表
		maxlen := max(len(words[i]), len(words[i-1]))
		flag := false
		for j := 0; j < maxlen; j++ { // 遍历单词
			if len(words[i-1]) < j+1 && j+1 <= len(words[i]) { // 上一个单词end
				_, ok := nodeMap[words[i][j]]
				if !ok {
					nodeMap[words[i][j]] = 0
				}
				continue
			}else if len(words[i-1]) >= j+1 && j+1 > len(words[i]){ // 后面单词结束
				if !flag {
					return ""
				}
				_, ok := nodeMap[words[i-1][j]]
				if !ok {
					nodeMap[words[i-1][j]] = 0
				}
				continue
			}else {
				_, ok := nodeMap[words[i][j]]
				if !ok {
					nodeMap[words[i][j]] = 0
				}

				_, ok = nodeMap[words[i-1][j]]
				if !ok {
					nodeMap[words[i-1][j]] = 0
				}
			}

			if words[i-1][j] == words[i][j] { // 相等
				continue
			}

			if flag {
				continue
			}

			flag = true
			// 构建图 a->b
			bytes := make([]byte, 2)
			bytes[0] = words[i-1][j] // a
			bytes[1] = words[i][j]   // b
			edges = append(edges, bytes)
			nodeMap[bytes[1]]++ // 入度+1
			continue
		}

	}

	// 入度等于0的点集合
	nodeZeros := make([]byte, 0, 4)
	for k, v := range nodeMap {
		//fmt.Println(k, "&", v)
		if v > 0 {
			continue
		}

		nodeZeros = append(nodeZeros, k)
	}

	result := make([]byte, 0, len(nodeMap))
	for len(nodeZeros) > 0 {
		node := nodeZeros[len(nodeZeros)-1]
		nodeZeros = nodeZeros[:len(nodeZeros)-1]
		nodeMap[node]--
		//fmt.Println(fmt.Sprintf("%c", node))
		result = append(result, node)
		for _, edge := range edges {
			if edge[0] != node {
				continue
			}

			nodeMap[edge[1]]--
			if nodeMap[edge[1]] == 0 {
				nodeZeros = append([]byte{edge[1]}, nodeZeros...)
			}
		}
	}

	if len(result) != len(nodeMap) {
		return ""
	}

	return string(result)
}

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}
```