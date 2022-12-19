直接用前缀函数判断前缀，两重循环，实际上函数里面还得加一重。

![image.png](https://pic.leetcode-cn.com/0ee78b610ea2e9abf3dfb6d753d6296d36a0bd8dae8dcbd7ab38468f8f952716-image.png)

```python []
class Solution:
    def replaceWords(self, dict: List[str], sentence: str) -> str:
        dict.sort()
        s = sentence.split(' ')
        for i, word in enumerate(s):
            for j in dict:
                if word.startswith(j):
                    s[i] = j
                    break
        return ' '.join(s)
```

生成前缀树，判断是否存在前缀，单词迭代。

![image.png](https://pic.leetcode-cn.com/1a494bd836b1d0a4ad38f6b7495d0d85572339798d79151c4ac1ed537b00bc43-image.png)

```python []
class Solution:
    def replaceWords(self, dict: List[str], sentence: str) -> str:
        d = {}              #字典树初始化
        for word in dict:   #把前缀放进字典树
            t = d
            for c in word:
                if c not in t:
                    t[c] = {}
                t = t[c]
            t['end'] = True
        def f(word):        #单词前缀判断
            t = d
            for i, c in enumerate(word):
                if 'end' in t:
                    return word[: i]    #存在前缀就返回前缀
                elif c not in t:
                    break               #不存在前缀就跳出循环并返回原词
                t = t[c]
            return word
        return ' '.join(map(f, sentence.split(' ')))
```

