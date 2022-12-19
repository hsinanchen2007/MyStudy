这题的代码，是在208前缀树的基础上，先对前缀树做了一些改动，再使用前缀树的方式解决问题。
相当于leetcode官方题解的go实现版本。
代码如下：
```
type Trie struct {
	ending int
	next [26]*Trie
}


/** Initialize your data structure here. */
func Constructor() Trie {
	return Trie{}
}


/** Inserts a word into the trie. */
func (this *Trie) Insert(word string, i int)  {
	temp:=this
	for _,v:=range word {
		nxt:=v-'a'
		if temp.next[nxt]==nil {
			temp.next[nxt]=&Trie{}
		}
		temp=temp.next[nxt]
	}
	temp.ending=i
}

/** Inserts a word into the trie. */
func (this *Trie) InsertWords(words []string, i int)  {
	for k,v:=range words {
		this.Insert(v,k+1)
	}
}

func (this *Trie) dfs(words []string) string {
	ans:=""
	stack:=[]*Trie{this}
	for len(stack)>0{
		node:=stack[len(stack)-1]
		stack=stack[:len(stack)-1]
		if node.ending>0||node==this {
			if node!=this {
				tempword:=words[node.ending-1]
				if len(tempword)>len(ans)||(len(tempword)==len(ans)&&strings.Compare(ans,tempword)>1) {
					ans=tempword
				}
			}
			for _,v :=range node.next{
				if v!=nil {
					stack=append(stack, v)
				}
			}
		}
	}
	return ans
}

func longestWord(words []string) string {
	trie:=Trie{}
	trie.InsertWords(words,1)
	return trie.dfs(words)
}
```
