### 解题思路
1. 构造 Trie 树，用来判断前缀是否存在
2. 对于每一种长度分别进行 BFS 搜索，可以利用对称的特点减少循环次数
    - 队列的每一项都保存 Trie 树中的节点列表
    - 判断字符串是否添加的时候，只需要判断上次的Trie树节点列表中每一项是否都有子节点

还有优化空间



### 代码

```golang
package main

import (
	"container/list"
	"sort"
)

type node struct {
	val    byte
	childs map[byte]*node
}

func add(root *node, word string) {
	p := root
	for i := range word {
		c := word[i]
		if _, ok := p.childs[c]; !ok {
			p.childs[c] = &node{c, map[byte]*node{}}
		}
		p = p.childs[c]
	}
}

func maxRectangle(words []string) []string {
	root := &node{0, map[byte]*node{}}
	lenD := map[int][]string{}
	for _, word := range words {
		add(root, word)
		lenD[len(word)] = append(lenD[len(word)], word)
	}

	lens := []int{}
	for i := range lenD {
		lens = append(lens, i)
	}
	sort.Sort(sort.Reverse(sort.IntSlice(lens)))

	type item struct {
		index []int
		nodes []*node
	}

	res, area := []string{}, 0
	maxL := 0
	for _, l := range lens {
		if l <= maxL {
			continue
		}
		queue := list.New()
		nodes := []*node{}
		for i := 0; i < l; i++ {
			nodes = append(nodes, root)
		}
		queue.PushBack(item{[]int{}, nodes})
		for queue.Len() > 0 {
			e := queue.Front()
			queue.Remove(e)
			ev := e.Value.(item)
			for i, word := range lenD[l] {
				flag := true
				nodes := []*node{}
				for j := range word {
					if _, ok := ev.nodes[j].childs[word[j]]; !ok {
						flag = false
						break
					} else {
						nodes = append(nodes, ev.nodes[j].childs[word[j]])
					}
				}
				if flag {
					tmpIndex := make([]int, len(ev.index), len(ev.index)+1)
					copy(tmpIndex, ev.index)
					tmpIndex = append(tmpIndex, i)
					queue.PushBack(item{tmpIndex, nodes})
					if len(tmpIndex) > maxL {
						maxL = len(tmpIndex)
					}
					if l*(len(ev.index)+1) > area {
						area = l * (len(ev.index) + 1)
						res = []string{}
						for _, i := range queue.Back().Value.(item).index {
							res = append(res, lenD[l][i])
						}
					}
				}

			}
		}
	}
	return res
}

```