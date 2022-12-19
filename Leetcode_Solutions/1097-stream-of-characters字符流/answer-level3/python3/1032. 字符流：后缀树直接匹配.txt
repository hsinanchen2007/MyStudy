![image.png](https://pic.leetcode-cn.com/c60df6ba51d816c00141d9c2867ca6aa6e0e341895491bbde90fef2d1d117745-image.png)

先把单词生成后缀树，然后再全局记录一下倒序串，查询的时候直接匹配就行了，一次就100%AC还行。

```python []
class StreamChecker:

    def __init__(self, words: List[str]):
        self.d = {}                 #后缀树初始化
        for word in words:          #遍历单词表
            t = self.d
            for c in word[:: -1]:   #生成后缀树
                if c not in t:
                    t[c] = {}
                t = t[c]
            t['end'] = True
        self.a = ''                 #倒序串初始化

    def query(self, letter: str) -> bool:
        self.a = letter + self.a    #倒序生成字符串
        t = self.d
        for c in self.a:            #后缀树匹配
            if c not in t:
                return False
            t = t[c]
            if 'end' in t:
                return True
        return False
```
