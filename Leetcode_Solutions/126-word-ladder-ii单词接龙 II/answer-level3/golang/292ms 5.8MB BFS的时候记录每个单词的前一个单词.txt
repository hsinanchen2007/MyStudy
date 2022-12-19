### 解题思路

BFS的时候使用一个map记录每个单词的前一个单词，然后再从endWork 基于这个map执行dfs来得到结果

### 代码

```golang

func findLadders(beginWord string, endWord string, wordList []string) [][]string {

	preMap := make(map[string][]string, 0)
	preMap = bfs(beginWord, endWord, wordList) //获取链表
	if preMap == nil {
		return nil
	}

	var prePath []string
	var result [][]string
	queryLadders(endWord, prePath, &result, preMap) //从后往前 再深度优先
	return result
}

func bfs(beginWord string, endWord string, wordList []string) map[string][]string {
	has := false
	for i := range wordList {
		if wordList[i] == endWord {
			has = true
			break
		}

	}
	if !has {
		return nil
	}

	preMap := make(map[string][]string, 0) //记录当前单词的父单词

	wordLen := len(wordList)
	used := make([]bool, wordLen)

	q := make([]string, 0)
	// m := make(map[string]struct{}, 0)

	q = append(q, beginWord)
	qLen := 1
	step := 1

	for i := range wordList {
		if wordList[i] == beginWord {
			used[i] = true //这里很重要
			break
		}

	}

	// m[beginWord] = struct{}{}

	for qLen > 0 {

		qMap := make(map[int]struct{}, 0) //保存下一层的节点

		for i := 0; i < qLen; i++ {

			cur := q[i]
			if cur == endWord {
				return preMap
			}

			for j := range wordList {

				if used[j] == false && hasOneDiff(cur, wordList[j]) {
					// q = append(q, wordList[j])
					// newLen++
					qMap[j] = struct{}{} // 和127题的区别，在同一层遍历的时候，j可能会重复访问，所以要用map 去重
					// used[j] = true 		//和127题的区别，这里不能就添加为访问过了，需要在这一层遍历过后统一设置used标记，不然就缺少了其它路径
					preMap[wordList[j]] = append(preMap[wordList[j]], cur)

				}

			}

		}

		//清空当前层
		q = q[:0:0]
		qLen = 0
		// 将下一层更新为当前层
		for k := range qMap {
			q = append(q, wordList[k])
			qLen++

			used[k] = true //统一设置为访问过
		}
		// q = q[qLen:]
		// qLen = len()

		step++
	}

	return nil

}

// 是否只有一个字符不一样
func hasOneDiff(a, b string) bool {

	dif := 0

	for i := range a {
		if a[i] != b[i] {
			dif++

			if dif > 1 {
				return false
			}
		}
	}

	return dif == 1

}

// 当前节点 root， prePath 是root之前的节点路径，不包含root
func queryLadders(root string, prePath []string, result *[][]string, parentMap map[string][]string) {
	prePath = append([]string{root}, prePath...)

	parents := parentMap[root]
	if len(parents) == 0 {
		prePath = append(prePath[:0:0], prePath...)
		*result = append(*result, prePath)
		return
	}
	for _, node := range parents {
		queryLadders(node, prePath, result, parentMap)

	}
	return

}

```