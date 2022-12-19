**方法一**：字典树，先把单词存进字典，在匹配的时候遇到‘.’就深搜，感觉和直接用正则差不多，虽然剪枝了，但还是不快：

![image.png](https://pic.leetcode-cn.com/65c19df815b0ce6399e210130335c8947d786e4bf08278f2be2c937c48d111aa-image.png)

```python []
class WordDictionary:

    def __init__(self):
        self.d = {}         #字典树

    def addWord(self, word: str) -> None:
        t = self.d          #单词填进字典树
        for c in word:
            if c not in t:
                t[c] = {}
            t = t[c]
        t['end'] = True

    def search(self, word: str) -> bool:
        cut = False
        def f(td, s):       #深搜，参数为：当前子字典，当前串
            nonlocal cut
            if cut:         #剪枝
                return True
            t = td
            for i, c in enumerate(s):
                if c == '.':
                    return any(f(t[j], s[i + 1: ]) for j in t if j != 'end')    #深搜扩展
                if c not in t:
                    return False
                t = t[c]
            cut = 'end' in t
            return cut
        return f(self.d, word)
```



**方法二**：按长度存进单词队列，枚举同长度的单词，然后逐个字母的对比，能够匹配的就返回正常。

![image.png](https://pic.leetcode-cn.com/8051a5112442890f9fa55191edb68daadfbf03f24547d2465f6a94a8b186a03d-image.png)

```python []
class WordDictionary:

    def __init__(self):
        self.d = collections.defaultdict(list)

    def addWord(self, word: str) -> None:
        self.d[len(word)] += [word]

    def search(self, word: str) -> bool:
        n = len(word)
        f = lambda s: all(map(lambda i: word[i] in {s[i], '.'}, range(n)))#匹配函数，比写正则要快不少
        return any(map(f, self.d[n]))
```


另附search函数扩写版：

```python
def search(self, word: str) -> bool:#扩写版
        n = len(word)
        def f(s):
            for i in range(n):
                if word[i] not in {s[i], '.'}:
                    return False
            return True
        for s in self.d[n]:
            if f(s):
                return True
        return False
```

**方法三：**

补一个正则吧，平均480ms这样。

```python []
class WordDictionary:

    def __init__(self):
        self.d = collections.defaultdict(str)

    def addWord(self, word: str) -> None:
        self.d[len(word)] += word + ' '

    def search(self, word: str) -> bool:
        return re.search(word.replace('.', '[a-z]'), self.d[len(word)])
```
