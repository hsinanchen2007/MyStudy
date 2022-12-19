golang 88ms 解决方案

```go
type WordDictionary struct {
	end  bool
	next *[27]*WordDictionary
}

/** Initialize your data structure here. */
func Constructor() WordDictionary {
	return WordDictionary{next: &[27]*WordDictionary{}}
}

/** Adds a word into the data structure. */
func (this *WordDictionary) AddWord(word string) {
	head := this
	for _, c := range word {
		var index rune
		if c == '.' {
			index = 26
		} else {
			index = c - 'a'
		}
		if nextNode := head.next[index]; nextNode == nil {
			trie := Constructor()
			nextNode = &trie
			head.next[index] = nextNode
			head = nextNode
		} else {
			head = nextNode
		}
	}
	head.end = true
}

/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
func (this *WordDictionary) Search(word string) bool {
	head := this
	for i, c := range word {
		if c == '.' {
			for _, next := range head.next {
				if next != nil {
					if next.Search(word[i+1:]) {
						return true
					}
				}
			}
			return false
		} else {
			index := c - 'a'
			if nextNode := head.next[index]; nextNode == nil {
				return false
			} else {
				head = nextNode
			}
		}
	}
	return head.end == true
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddWord(word);
 * param_2 := obj.Search(word);
 */
```