### 逆序直接判断是否为子串
```python
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        words.sort(key=lambda i:len(i), reverse=True) #按单词元素长度降序
        res = ''
        for word in words:
            if word+'#' in res:continue
            else: res+= word+'#'
        return len(res)
```

### 优化
```python
class Solution:
    def minmumLengthEncoding(self, words):
        res, N = '', len(words)
        words.sort(key=lambda word:word[::-1])
        for i in range(N):
            if i+1 < N and words[i+1].endswith(words[i]):continue
            else: res += words[i] + '#'
        return len(res)
```

### Trie字典树
```python
class Trie:
    def __init__(self):
        self.Trie = {}
    def insert(self, word):
        cur = self.Trie
        for w in word:
            if w not in cur:
                cur[w] = {}
            cur = cur[w]
        cur['#'] = 1
    def isTail(self, word):
        cur = self.Trie
        for w in word:
            cur = cur[w]
        return len(cur)==1

class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        trie = Trie()
        res = ''
        words = set(words)
        for word in words:
            trie.insert(word[::-1])
        for word in words:
            if trie.isTail(word[::-1]):res += word + '#'
        return len(res)
```