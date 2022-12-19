### 解题思路
包含 .的字符用深度优先搜索

即把当前节点的所有children都遍历一遍，这里用深度优先搜索，同时搜索字母的字符位置右移

注意DFS的结束条件
- word到头之后  判断node是否是isend
- word没到头，判断 node是否是 . 分别进行DFS
	- 如果是. 则对所有的children进行DFS，
	- 如果是普通字符，则对children[byte]进行DFS 

### 代码

```golang

type WordDictionary struct {
	isEnd    bool
	children map[byte]*WordDictionary
}

/** Initialize your data structure here. */
func Constructor() WordDictionary {
	return WordDictionary{false, make(map[byte]*WordDictionary)}
}

/** Adds a word into the data structure. */
func (this *WordDictionary) AddWord(word string) {
	p := this
	for i := 0; i < len(word); i++ {
		if _, ok := p.children[word[i]]; !ok {
			p.children[word[i]] = &WordDictionary{i == len(word)-1, make(map[byte]*WordDictionary)}
		}
		p = p.children[word[i]]
	}
	p.isEnd = true
}

/** Returns if the word is in the trie. */
func (this *WordDictionary) Search(word string) bool {
	return Search_trie(this, word, 0)
}

/** Returns if the word is in the trie. */
func Search_trie(node *WordDictionary, word string, i int) bool {
	if node == nil {
		return false
	}
	//trie 树 和word两个，分别看是否到头
	// 1. word到头了
	if i >= len(word) {
		if node.isEnd {
			return true
		}
		return false
	}
	p := node
	// 2. word 没到头
	if word[i] == '.' {
		// trie树到头了
		// 如果是 ".",就深度优先搜索遍历所有的children
		for k, _ := range p.children {
			if Search_trie(p.children[k], word, i+1) {
				return true
			}
		}
	} else {
		if _, ok := p.children[word[i]]; ok {
			if Search_trie(p.children[word[i]], word, i+1) {
				return true
			}
		}
	}
	return false
}

```