### 解题思路
构造前缀树，存储搜索过的单词和单词的次数。
在进行自动补全功能时，在前缀树中深搜前缀相同的单词，将搜索到的结果存入最小堆，只要将次数放在前取负，即可满足堆中取出的单词是按照次数从大到小，单词ASCII码从小到大的顺序。

代码中在搜索的过程每次都是从头开始搜索的，其实可以从前缀树中的当前字符开始搜索，只需要保持一个临时的前缀树对象每次搜索的时候拿来用即可。


### 代码

```python3
import heapq
class TrieNode:
    def __init__(self):
        self.next = {}
        self.isWord = False
        self.times = 0
    
class Trie:
    def __init__(self):
        self.root = TrieNode()
        
    def insert(self, word, times=1):
        cur = self.root
        for c in word:
            if c not in cur.next:
                cur.next[c] = TrieNode()
            cur = cur.next[c]
        cur.isWord = True
        cur.times += times
    
    def search(self, word):
        cur = self.root
        for c in word:
            if c not in cur.next:
                return []
            cur = cur.next[c]
        res, path = [], [word]
        self.dfs(cur, res, path)
        return res
    
    def dfs(self, cur, res, path):
        if cur.isWord:
            res.append((-cur.times, ''.join(path)))
        for c in cur.next:
            path.append(c)
            self.dfs(cur.next[c], res, path)
            path.pop()
    
class AutocompleteSystem:

    def __init__(self, sentences: List[str], times: List[int]):
        self.root = Trie()
        self.exists = True
        self.path = ''
        for i in range(len(sentences)):
            self.root.insert(sentences[i], times[i])

    def input(self, c: str) -> List[str]:
        if c == '#':
            self.root.insert(self.path, 1)
            self.path = ''
            self.exists = True
            return []
        else:
            self.path += c
            if not self.exists:
                return []
            words = self.root.search(self.path)
            if words:
                heapq.heapify(words)
                res = []
                while words and len(res) < 3:
                    res.append(heapq.heappop(words)[1])
                return res
            else:
                self.exists = False
                return []
            

# Your AutocompleteSystem object will be instantiated and called as such:
# obj = AutocompleteSystem(sentences, times)
# param_1 = obj.input(c)
```