### 解题思路
此处撰写解题思路

### 代码
执行用时 :424 ms, 在所有 Go 提交中击败了12.95%的用户
内存消耗 :6.3 MB, 在所有 Go 提交中击败了41.00%的用户
```golang

package main

import (
	"math"
)

func ladderLength(beginWord string, endWord string, wordList []string) int {
	//定义候选单词表(即跟beginword相同或只相差一个字符的单词)
	candidate := make([]string, 0)
	//定义邻接表
	adjacencyTable := make(map[string][]string)
	for i:=0; i < len(wordList); i++ {
		adjacencyTable[wordList[i]] = make([]string,0)
	}
	//初始化邻接表
	for i:=0; i < len(wordList); i++ {
		for j := i+1; j < len(wordList); j++ {
			diff := 0
			for idx := 0; idx < len(wordList[i]); idx++{
				if diff <= 2 && wordList[i][idx] != wordList[j][idx] {
					diff++
				}
			}
			if diff == 1 {
				arr1 := adjacencyTable[wordList[i]]
				adjacencyTable[wordList[i]] = append(arr1, wordList[j])
				arr2 := adjacencyTable[wordList[j]]
				adjacencyTable[wordList[j]] = append(arr2, wordList[i])
			}
		}
	}
	if _, ok := adjacencyTable[beginWord]; ok {
		candidate = []string{beginWord}
	}else{
		for _, word := range wordList {
			diff := 0
			for idx := 0; idx < len(word); idx ++ {
				if diff <= 2 && word[idx] != beginWord[idx] {
					diff++
				}
			}
			if diff == 1 {
				candidate = append(candidate, word)
			}
		}
	}

	//递归求解
	result := math.MaxInt32
	for _, start := range candidate{
		//说明beginword是wordlist中的单词，则直接求解
		step := search(start, endWord, adjacencyTable)
		if step == 0 {
			continue
		}
		result = min(result, step)
	}
	if result == math.MaxInt32 {
		return 0
	}
	if _,ok := adjacencyTable[beginWord];ok {
		return result
	}
	return result+1
}

func search(start, end string, adjacencyTable map[string][]string) int {
	visit := make(map[string]struct{},0)
	visit[start] = struct{}{}
	level := 1
	queue := []string{start}
	length := len(queue)
	for length != 0 {
		for ; length != 0; length--{
			curr := queue[0]
			if curr == end {
				return level
			}
			for _, word := range adjacencyTable[curr] {
				if _,ok :=visit[word];ok {
					continue
				}
				queue = append(queue, word)
				visit[word] = struct{}{}
			}
			queue = queue[1:]
		}
		level++
		length = len(queue)
	}
	return 0
}

func min(a, b int) int {
	if a < b {
		return a
	}else{
		return b
	}
}

```