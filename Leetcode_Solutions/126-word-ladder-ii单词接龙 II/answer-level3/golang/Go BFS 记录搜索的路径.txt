### 解题思路
一：构造图，用邻接表来表示
1. 宽度优先搜索的队列，宽度优先搜索时不pop，而是通过front指针来模拟pop，即front后移动
2. 加入到队列的判断条件与127题有所不同，这里是当没有搜索过，或者搜索过了，但是与搜索过的路径到达该节点所用的步数一致

### 代码

```golang
func findLadders(beginWord string, endWord string, wordList []string) [][]string {
	var has bool
	for i:=0;i< len(wordList);i++{
		if wordList[i]==beginWord{
			has=true
		}
	}
	if !has{
		wordList= append(wordList, beginWord)
	}
	
	length := len(wordList)
	grap := make(map[string][]string, length)
	construct_graph(beginWord, wordList, grap)
	var end_word_pos []int
	var Q []queueNode
	BFS_Graph(beginWord, endWord, grap, &Q, &end_word_pos)
	var res [][]string = make([][]string, len(end_word_pos))
	for i := 0; i < len(end_word_pos); i++ {
		pos := end_word_pos[i]
		var path []string
		for pos != -1 {
			path = append(path, Q[pos].node)
			pos = Q[pos].parent_pos
		}
		for j := len(path) - 1; j >= 0; j-- {
			res[i] = append(res[i], path[j])
		}
	}
	return res
}

func connect(word1, word2 string) bool {
	var cnt int
	for i := 0; i < len(word1); i++ {
		if word1[i] != word2[i] {
			cnt++
		}
	}
	if cnt != 1 {
		return false
	}
	return true
}
func construct_graph(begin string, wordlist []string, graph map[string][]string) {

	for i := 0; i < len(wordlist); i++ {
		for j := i + 1; j < len(wordlist); j++ {
			// 根据是否相连构建邻接表
			if connect(wordlist[i], wordlist[j]) {
				graph[wordlist[i]] = append(graph[wordlist[i]], wordlist[j])
				graph[wordlist[j]] = append(graph[wordlist[j]], wordlist[i])
			}
		}
	}
}

type queueNode struct {
	node       string
	step       int
	parent_pos int // 前驱节点在队列在队列中的位置
}

func BFS_Graph(beginWord string, endWord string, graph map[string][]string, Q *[]queueNode, end_word_pos *[]int) {
	var visited = make(map[string]int)
	*Q = append(*Q, queueNode{beginWord, 1, -1})

	visited[beginWord] = 1 // 标记其实单词的步数为1
	min_step := 0
	front := 0

	for len(*Q) != front { // front走到底时，队列为空
		// pop
		node := (*Q)[front]
		step := node.step
		if min_step != 0 && step > min_step {
			break
		}
		if node.node == endWord {
			min_step = node.step
			*end_word_pos = append(*end_word_pos, front)
		}
		list := graph[node.node]
		for i := 0; i < len(list); i++ {
			if _, ok := visited[list[i]]; !ok || visited[list[i]] == step+1 { // 没有访问过，或者访问过但是正好是该节点的下个节点，即另外一条最短路径
				*Q = append(*Q, queueNode{list[i], step + 1, front})
				visited[list[i]] = step + 1
			}
		}
		front++
	}
}
```