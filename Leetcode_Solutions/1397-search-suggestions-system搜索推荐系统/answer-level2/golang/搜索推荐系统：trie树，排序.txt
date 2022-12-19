## 方法一：sort + binary search

- 排序+二分查找
- 二分查找看似简单，但是稍微变化写出bug free的代码还是有难度的
- 此题为二分查找的变形：找到数组中要第一个大于等于给定值的元素位置


```
func suggestedProducts(products []string, searchWord string) [][]string {
	if products == nil || len(products) == 0 || searchWord == "" {
		return nil
	}
	sort.Slice(products, func(i, j int) bool {
		return products[i] < products[j]
	})
	results := make([][]string, 0)
	for i := 0; i < len(searchWord); i++ {
		cnt := 0
		result := make([]string, 0)
		word := searchWord[:i+1]
		index := bSearch(products, word)
		if index == -1 {
			results = append(results, []string{})
		} else {
			for j := index; j < len(products) && cnt < 3; j++ {
				if strings.HasPrefix(products[j], word) {
					result = append(result, products[j])
					cnt++
				} else {
					break
				}
			}
			results = append(results, result)
		}
	}
	return results
}

func bSearch(products []string, word string) int {
	left, right := 0, len(products)-1
	for left <= right {
		mid := left + (right-left)/2
		if products[mid] >= word {
			if mid == 0 || products[mid-1] < word {
				return mid
			} else {
				right = mid - 1
			}
		} else {
			left = mid + 1
		}
	}
	return -1
}
```

## 方法二： trie树 + dfs

- trie树写起来还是有点复杂的
- 题目中有个坑：数组中可能存在重复的元素，求解答案中也能包含重复的元素

```
// ops: products can contain duplicated product
// for example: ["mobile","mobile","mouse","moneypot","monitor","mousepad"]
var words []string
var cnt int

// trie + bfs
func suggestedProducts(products []string, searchWord string) [][]string {
	if products == nil || len(products) == 0 || searchWord == "" {
		return nil
	}
	words = make([]string, 0)
	cnt = 0
	trie := constructTrie(products)
	results := make([][]string, 0)
	tempTrie := trie
	var preStr []byte
	for i := 0; i < len(searchWord); i++ {
		words = make([]string, 0)
		cnt = 0
		index := searchWord[i] - 'a'
		if tempTrie.children[index] == nil {
			results = append(results, []string{})
			tempTrie = newTrieNode(' ', false) // ops
		} else {
			preStr = append(preStr, tempTrie.children[index].val)
			tempTrie = tempTrie.children[index]
			dfs(tempTrie, preStr)
			results = append(results, words)
		}
	}
	return results
}

type TrieNode struct {
	val      byte
	children []*TrieNode
	isWorld  bool
	cnt      int
}

func newTrieNode(val byte, isWorld bool) *TrieNode {
	var trieNode TrieNode
	trieNode.val = val
	trieNode.children = make([]*TrieNode, 26)
	trieNode.isWorld = isWorld
	if isWorld {
		trieNode.cnt++
	}
	return &trieNode
}

func constructTrie(products []string) *TrieNode {
	tries := make([]*TrieNode, 26)
	for _, pro := range products {
		tempTries := tries
		for i := 0; i < len(pro); i++ {
			isWorld := false
			if i == len(pro)-1 {
				isWorld = true
			}
			if tempTries[pro[i]-'a'] == nil {
				tempTries[pro[i]-'a'] = newTrieNode(pro[i], isWorld)
			} else if isWorld { // ops
				tempTries[pro[i]-'a'].cnt++
				tempTries[pro[i]-'a'].isWorld = true
			}
			tempTries = tempTries[pro[i]-'a'].children
		}
	}
	trie := newTrieNode(' ', false)
	trie.children = tries
	return trie
}

func dfs(trie *TrieNode, result []byte) {
	if trie.cnt > 0 {
		for i := 0; i < trie.cnt && cnt < 3; i++ {
			words = append(words, string(result))
			cnt++
		}
	}
	if cnt >= 3 {
		return
	}
	for _, child := range trie.children {
		if child != nil {
			result = append(result, child.val)
			dfs(child, result)
			result = result[:len(result)-1]
		}
	}
}
```




