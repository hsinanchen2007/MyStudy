
#### 解题思路

根据题目中给出的字母建立前缀树，其中前缀树的每是长度为26的Node指针切片，每层字母按倒序存储，例如，字母“a”存放在切片的第25个位置上，然后进行广度优先遍历，最后遍历的一个字符所在的字符串即是所求字符串


#### 参考代码

```go
package LongestWordInDictionary

import (
	 "container/list"
)

func longestWord(words []string) string {
	 t := Trie{
		root:  NodeConstructor("0"),
	}
	for i:=0;i<len(words);i++ {
		t.insert(words[i],i)
	}
	t.words = words

	return t.bfs()
}

type Node struct {
	s string
	children [26]*Node
	index int
}

func NodeConstructor(str string) *Node{
	return &Node{s:str,index:-1}
}

type Trie struct {
	root *Node
	words []string
}

func (t *Trie) insert(word string,index int){
	cur:=t.root
	length:=len(word)
	for i:=0;i<length;i++ {
		n := 25-(word[i]-'a')
		if cur.children[n] == nil {
			cur.children[n] = NodeConstructor(string(word[i]))
		}
		cur = cur.children[n]
	}
	cur.index = index
}

func (t *Trie) bfs() string {
	queue := list.New()
	queue.PushBack(t.root)
	var finalroot *Node
	for queue.Len()>0 {
		root:= queue.Front()
		queue.Remove(root)
		if cur,ok := root.Value.(*Node);ok{
			for i:=0;i<len(cur.children);i++ {
				if cur.children[i]!=nil && cur.children[i].index!=cur.index && cur.children[i].index!=-1{
					queue.PushBack(cur.children[i])
				}
				finalroot = cur
			}
		}

	}
	return t.words[finalroot.index]

}

```

**更多题解可以在我的[github](https://github.com/LZH139/leetcode_Go)上看到，每天都在持续更新，觉得还不错的话，记得点个小星星哈，谢谢啦**

