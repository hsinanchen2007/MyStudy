### 解题思路
尝试改进了一下themoonston的代码  https://leetcode-cn.com/problems/word-ladder/solution/golang-shi-xian-de-shuang-xiang-bfs-by-themoonston/
在替换word的字符时，判断target是否在wordlist中，若不在则直接continue，尝试下一种替换。（时间可从60ms下降至20ms）
### 代码
执行用时 :20 ms, 在所有 Go 提交中击败了95.68%的用户
内存消耗 :5.8 MB, 在所有 Go 提交中击败了68.00%的用户
```golang
package main

func ladderLength(beginWord string, endWord string, wordList []string) int {
	m_set, visit := make(map[string]bool, 0), make(map[string]bool, 0)
	for _, word := range wordList {
		m_set[word] = true
	}
    if !m_set[endWord] {
        return 0
    }
	beginQueue := []string{beginWord}
	endQueue := []string{endWord}
	round := 0
	for len(beginQueue) > 0 && len(endQueue) > 0 {
		round++
		if len(beginQueue) > len(endQueue) {
			beginQueue, endQueue = endQueue, beginQueue
		}
		nextQ := make([]string, 0)
		for _, word := range beginQueue {
			str := []byte(word)
			for i := 0; i < len(str); i++ {
				oriC :=  str[i]
				for c:='a'; c <= 'z'; c++ {
					str[i] = byte(c)
					target := string(str)
                    if !m_set[target] {
                        continue
                    }
					if contains(endQueue, target) {
						return round+1
					}
					if !visit[target] {
						visit[target] = true
						nextQ = append(nextQ, target)
					}
				}
				str[i] = oriC
			}
		}
		beginQueue = nextQ
	}
	return 0
}

func contains(list []string, target string) bool {
	for _, word := range list {
		if target == word {
			return true
		}
	}
	return false
}

```