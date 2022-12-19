- 通过两次 BFS 找出图的直径
- 第三次 BFS 找出直径中的 length/2 的元素
- 代码写得比较搓

```
import (
	"container/list"
)

func findMinHeightTrees(n int, edges [][]int) (rst []int) {
	var (
		i, j, neigboNode, lastNode, currLevel, maxLevel int
		length                                          = len(edges)
		l                                               = list.New()
		currLevelCount, nextLevelCount                  int
		visitedMap                                      = map[int]bool{}
		graph                                           = make([][]int, n)
	)

	for i = 0; i < length; i++ {
		graph[edges[i][0]] = append(graph[edges[i][0]], edges[i][1])
		graph[edges[i][1]] = append(graph[edges[i][1]], edges[i][0])
	}

	l.PushBack(0)
	currLevelCount = 1
	for l.Len() != 0 {
		nextLevelCount = 0
		for j = 0; j < currLevelCount; j++ {
			node := l.Remove(l.Front()).(int)
			visitedMap[node] = true
			lastNode = node
			for _, neigboNode = range graph[node] {
				if visitedMap[neigboNode] {
					continue
				}
				l.PushBack(neigboNode)
				nextLevelCount++
			}
		}
		currLevelCount = nextLevelCount
	}
	l.PushBack(lastNode)
	visitedMap = map[int]bool{
		lastNode: true,
	}
	currLevelCount = 1
	for l.Len() != 0 {
		currLevel++
		nextLevelCount = 0
		for j = 0; j < currLevelCount; j++ {
			node := l.Remove(l.Front()).(int)
			visitedMap[node] = true
			lastNode = node
			for _, neigboNode = range graph[node] {
				if visitedMap[neigboNode] {
					continue
				}
				l.PushBack(neigboNode)
				nextLevelCount++
			}
		}
		currLevelCount = nextLevelCount
	}
	maxLevel = currLevel

	l.PushBack(path{
		Node: lastNode,
		Path: []int{lastNode},
	})
	visitedMap = map[int]bool{
		lastNode: true,
	}
	currLevel = 0
	currLevelCount = 1
	for l.Len() != 0 {
		currLevel++
		nextLevelCount = 0
		for j = 0; j < currLevelCount; j++ {
			node := l.Remove(l.Front()).(path)
			visitedMap[node.Node] = true
			if currLevel == maxLevel {
				if maxLevel%2 == 0 {
					return []int{node.Path[maxLevel/2-1],
						node.Path[maxLevel/2]}
				} else {
					return []int{node.Path[maxLevel/2]}
				}
			} else {
				for _, neigboNode = range graph[node.Node] {
					if visitedMap[neigboNode] {
						continue
					}
					newPath := make([]int, len(node.Path)+1)
					copy(newPath, append(node.Path, neigboNode))
					l.PushBack(path{
						Node: neigboNode,
						Path: newPath,
					})
					nextLevelCount++
				}
			}
		}
		currLevelCount = nextLevelCount
	}

	return
}

type path struct {
	Node int
	Path []int
}
```
