```
class WordFilter:

    def __init__(self, words: List[str]):
        self.words = words
        self.map = {}
        self.indexmap = {}
        for i in range(len(words)):
            c = words[i][0]
            if c in self.map:
                self.map[c].append(words[i])
                self.indexmap[c].append(i)
            else:
                l1 = []
                l1.append(words[i])
                self.map[c] = l1        
                l2 = []
                l2.append(i)
                self.indexmap[c]=l2

    def f(self, prefix: str, suffix: str) -> int:
        if prefix == None or prefix=="":    #没有前缀条件，直接搜索后
            for i in range(len(self.words)-1,-1,-1): 
                if self.words[i].endswith(suffix):
                    return i
            
        else:    #从相同首字母的单词中搜索
            c = prefix[0]
            if c not in self.map:
                return -1
            l1 = self.map[c]
            l2 = self.indexmap[c]
            for i in range(len(l1)-1,-1,-1):
                if l1[i].startswith(prefix) and l1[i].endswith(suffix):
                    return l2[i]
        return -1
```
