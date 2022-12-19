### 解题思路

预处理单词到通配符以及通配符到单词的路径，用字典来作为层次宽搜的容器进行宽搜扩展即可。

### 代码

```python []
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[str]:
        d = collections.defaultdict(list)
        for word in wordList + [beginWord]:
            w = [*word]
            for i, c in enumerate(word):
                w[i] = '.'
                p = ''.join(w)
                d[p].append(word)
                d[word].append(p)
                w[i] = c
        if endWord in d:
            q, v = {beginWord: [beginWord]}, {beginWord}
            while q:
                if endWord in q:
                    return q[endWord]
                q = {w: [*q[i], w] for i in q for j in d[i] for w in d[j] if w not in v}
                v.update(q.keys())
        return []
```
```python []
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[str]:
        alpha = 'abcdefghijklmnopqrstuvwxyz'
        notvst = {*wordList}
        n = len(endWord)
        if endWord in notvst:
            q = {beginWord: [beginWord]}
            while q:
                if endWord in q:
                    return q[endWord]
                t = {}
                for v in q:
                    for i in range(n):
                        for c in alpha:
                            w = v[: i] + c + v[i + 1: ]
                            if w in notvst:
                                t[w] = q[v] + [w]
                                notvst.remove(w)
                q = t
        return []
```
