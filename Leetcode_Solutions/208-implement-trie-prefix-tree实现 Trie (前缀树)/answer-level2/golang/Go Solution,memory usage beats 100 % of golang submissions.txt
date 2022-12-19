```
type Trie struct {
	ret map[string]bool
}

/** Initialize your data structure here. */
func Constructor() Trie {
	return Trie{
		ret: make(map[string]bool),
	}
}

/** Inserts a word into the trie. */
func (this *Trie) Insert(word string) {
	this.ret[word] = true
}

/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
	return this.ret[word]

}

/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
	if this.ret[prefix] {
		return true
	}

	for i := range this.ret {
		var flag int 
		if len(i) < len(prefix) {
			continue
		}

		for k := range prefix {
			if i[k] != prefix[k] {
				break
			} else {
				flag++
			}
			
			if flag == len(prefix) {
				return true
			}
		}
	}
	return false

}
```
