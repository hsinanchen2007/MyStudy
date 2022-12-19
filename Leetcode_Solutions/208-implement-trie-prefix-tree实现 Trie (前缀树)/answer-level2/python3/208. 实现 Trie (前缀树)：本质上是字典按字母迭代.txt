![image.png](https://pic.leetcode-cn.com/a81a0392e4ef98c7a1ca134f3765265147bb11c90b8acb4ade8e81f85ba55d5f-image.png)


以样例为例，在两次insert插入后，迭代出来的字典会有如下表达，end表示：在这个字母的位置存在某个单词的结尾
```py
apple:{'a': {'p': {'p': {'l': {'e': {'end': True}}}}}}             #第一次insert，最后一个'e'存在结束'end'
app:  {'a': {'p': {'p': {'l': {'e': {'end': True}}, 'end': True}}}}#第二次insert，第二个'p'存在结束'end'
```


```python []
class Trie:
    def __init__(self):
        self.d = {}
        
    def insert(self, word: str) -> None:
        t = self.d
        for c in word:
            if c not in t:
                t[c] = {}
            t = t[c]        #字典迭代
        t['end'] = True     #标记单词终点

    def search(self, word: str) -> bool:
        t = self.d
        for c in word:
            if c not in t:
                return False
            t = t[c]
        return 'end' in t

    def startsWith(self, prefix: str) -> bool:
        t = self.d
        for c in prefix:
            if c not in t:
                return False
            t = t[c]
        return True
```
