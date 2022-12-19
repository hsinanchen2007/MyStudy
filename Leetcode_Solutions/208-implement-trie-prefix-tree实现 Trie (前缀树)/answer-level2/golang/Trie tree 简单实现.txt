```
type Trie struct {
	Next        [26]*Trie
	isEndOfWord bool
}

/** Initialize your data structure here. */
func Constructor() Trie {
	return Trie{}
}

/** Inserts a word into the trie. */
func (this *Trie) Insert(word string) {
	for _, c := range word {
		c -= 'a'
		if ok := this.Next[c]; ok == nil {
			this.Next[c] = new(Trie)
		}
		this = this.Next[c]
	}
	this.isEndOfWord = true
}

/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	for _, v := range word {
		if this = this.Next[v-'a']; this == nil {
			return false
		}
	}
	return this.isEndOfWord
}

/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	for _, v := range prefix {
		if this = this.Next[v-'a']; this == nil {
			return false
		}
	}
	return true
}}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
```
