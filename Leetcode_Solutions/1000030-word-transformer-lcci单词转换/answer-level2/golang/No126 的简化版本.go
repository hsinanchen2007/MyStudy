### 代码

```golang
import (
	"container/list"
)

type Node struct {
	Idx  int
	Path []string
}

func findLadders(beginWord string, endWord string, wordList []string) []string {
	var (
		transformMap                                        = map[int]map[int]bool{}
		length                                              = len(wordList) + 1
		visitedMap                                          = map[int]bool{}
		tmpVisitedMap                                       = map[int]bool{}
		containBegin, containEnd                            bool
		beginIdx, endIdx, currLength, NextLevelLength, i, j int
		rst                                                 = [][]string{}
	)

	// 判断是否 begin 和 end word 都在数组中，
	// - 如果 begin 不在，为了后面的 transform map 需要将 begin 加来
	// - 如果 end 不在，那直接返回了
	for idx, word := range wordList {
		if word == endWord {
			containEnd = true
			endIdx = idx
		}
		if word == beginWord {
			containBegin = true
			beginIdx = idx
		}
		transformMap[idx] = map[int]bool{}
	}
	if !containEnd {
		return []string{}
	}
	if !containBegin {
		transformMap[length-1] = map[int]bool{}
		beginIdx = len(wordList)
		wordList = append(wordList, beginWord)
	} else {
		length--
	}

	// 构造 transform map，即 wordList[i] 是否可以转换位 wordList[j]
	for i = 0; i < length; i++ {
		for j = i + 1; j < length; j++ {
			if isTransform(wordList[i], wordList[j]) {
				transformMap[i][j] = true
				transformMap[j][i] = true
			}
		}
	}

	// 根据转换的 map，从 begin word 开始进行 bfs
	// 通过 visitedMap 进行剪枝
	var q = list.New()
	currLength = 1
	q.PushBack(Node{
		Idx:  beginIdx,
		Path: []string{beginWord},
	})
	for currLength != 0 {
		NextLevelLength = 0
		tmpVisitedMap = map[int]bool{}
		for i = 0; i < currLength; i++ {
			n := q.Remove(q.Front()).(Node)
			if len(transformMap[n.Idx]) == 0 {
				continue
			}
			for idx, _ := range transformMap[n.Idx] {
				if idx == endIdx {
					path := make([]string, len(n.Path)+1)
					copy(path, append(n.Path, endWord))
					rst = append(rst, path)
					continue
				}
				if visitedMap[idx] {
					continue
				}
				tmpVisitedMap[idx] = true
				node := Node{Idx: idx,
					Path: make([]string, len(n.Path)+1),
				}
				copy(node.Path, append(n.Path, wordList[idx]))
				q.PushBack(node)
				NextLevelLength++
			}
		}

		for idx, _ := range tmpVisitedMap {
			visitedMap[idx] = true
		}
		if len(rst) != 0 {
			return rst[0]
		}
		currLength = NextLevelLength
	}

	return nil
}

func isTransform(a, b string) bool {
	notEqual := false
	for idx, x := range a {
		if uint8(x) != b[idx] {
			if notEqual {
				return false
			}
			notEqual = true
		}
	}
	return notEqual
}

```