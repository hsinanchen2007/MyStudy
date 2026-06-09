只要会字典树，题目还是很简单的，时间要求也不是很高2000ms都可以过
字典树的构造就不详述了，主要就是添加 isEnd标记是否是一个单词的结尾

- 前缀树（2000ms）
每次查询的时候记录所有成功匹配到的节点
下次查询时直接查询上次存储的节点

- 后缀树 (500ms)
 每次从树根开始查，如果不是结尾，直接返回即可
```
type StreamChecker struct {
	Trie *Trie
	LastTries []*Trie
}

type Trie struct {
	isEnd bool
	childs [26]*Trie
}

func Constructor(words []string) StreamChecker {
	exists := make(map[string]bool)
	trie := &Trie{
		childs: [26]*Trie{},
	}
	for i := 0; i < len(words); i++ {
		if exists[words[i]] {
			continue
		}
		trie.Insert(words[i])
		exists[words[i]] = true
	}
	return StreamChecker{
		Trie: trie,
		LastTries: make([]*Trie, 0),
	}
}


func (this *StreamChecker) Query(letter byte) bool {
	ret := false
	newTries := make([]*Trie, 0, 1000)
	lett := int(letter - 'a')
	for i := 0; i < len(this.LastTries); i++ {
		if this.LastTries[i].childs[lett] != nil {
			child := this.LastTries[i].childs[lett]
			if child.isEnd {
				ret = true
			}
			newTries = append(newTries, child)
		}
	}
	if this.Trie.childs[lett] != nil {
		child := this.Trie.childs[lett]
		newTries = append(newTries, child)
		if child.isEnd {
			ret = true
		}
	}
	this.LastTries = newTries
	return ret
}

func (this *Trie) Insert(word string) {
	if len(word) == 0 {
		return
	}
	t := this
	for i := 0; i < len(word); i++ {
		v := int(word[i] - 'a')
		if t.childs[v] == nil {
			t.childs[v] = &Trie{}
		}
		t = t.childs[v]
	}
    t.isEnd = true
}

```

```
type StreamChecker struct {
	Trie *Trie
    stream []byte
}

type Trie struct {
	isEnd bool
	childs [26]*Trie
}

func Constructor(words []string) StreamChecker {
	exists := make(map[string]bool)
	trie := &Trie{
		childs: [26]*Trie{},
	}
	for i := 0; i < len(words); i++ {
		if exists[words[i]] {
			continue
		}
		trie.Insert(words[i])
		exists[words[i]] = true
	}
	return StreamChecker{
		Trie: trie,
        stream: make([]byte, 0, 40000),
	}
}


func (this *StreamChecker) Query(letter byte) bool {
    this.stream = append(this.stream, letter)
    root := this.Trie
    for i := len(this.stream) - 1; i >= 0; i-- {
        v := int(this.stream[i] - 'a')
        root = root.childs[v]
        if root != nil {
            if root.isEnd {
                return true
            }
        } else {
            return false
        }
    }
	return false
}

func (this *Trie) Insert(word string) {
	if len(word) == 0 {
		return
	}
	t := this
    for i := len(word) - 1; i >= 0; i-- {
		v := int(word[i] - 'a')
		if t.childs[v] == nil {
			t.childs[v] = &Trie{}
		}
		t = t.childs[v]
	}
    t.isEnd = true
}
```