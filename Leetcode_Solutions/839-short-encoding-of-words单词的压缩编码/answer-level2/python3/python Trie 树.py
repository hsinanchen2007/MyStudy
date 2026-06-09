```
class Trie:
    def __init__(self):
        self.root={}
    def insert(self,word):
        p=self.root
        isNew=False
        for c in word[::-1]:
            if c not in p:
                p[c]={}
                isNew=True
            p=p[c]
        p["#"] =True 
        if isNew:
            return len(word)+1
        else:
            return 0
    
    def search(self,word):
        node=self.find(word)
        if node is not None and "#" in node:
            return True
        else:
            return False
    
    def startWith(self,prefix):
        if self.find(prefix):
            return True
        else:
            return False
    
    def find(self,prefix):
        p=self.root
        for c in prefix:
            if c not in p:
                return None
            p=p[c]
        return p

class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int
        res=0
        obj = Trie()
        # 单词按照字符长度排序,由长到短
        words.sort(key=lambda x:len(x),reverse=True)
        print(words)
        for word in words:
            res +=obj.insert(word)
        return res
```
