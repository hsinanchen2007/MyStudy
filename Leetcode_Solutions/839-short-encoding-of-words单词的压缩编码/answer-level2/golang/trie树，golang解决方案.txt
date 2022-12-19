```
func minimumLengthEncoding(words []string) int {
	l := 0

	t := &trie{
        &trieNode{},
    }


	for i := 0  ; i <len(words)-1 ; i++ {
		if len(words[i]) < len(words[i+1]){
			words[i],words[i+1] = words[i+1],words[i]
		}
	}

	for _,v := range words {
		l += t.insert(v)
	}
	return l
}



type trieNode struct {
	val rune
	children [26]*trieNode
}


type trie struct {
	root *trieNode
}

func (t *trie) insert(word string)int{
	cur := t.root
	isNew := false
	for i := len(word)-1 ; i>=0 ; i--{
		c := word[i] - 'a'
		if cur.children[c] == nil {
			isNew = true
			cur.children[c] = &trieNode{}
		}
		cur = cur.children[c]
	}
	if isNew {
		return len(word) + 1
	}
	return 0
}
```
