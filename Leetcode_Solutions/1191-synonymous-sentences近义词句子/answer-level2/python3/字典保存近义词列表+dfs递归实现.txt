思路很简单，把所有近义词保存在一个列表里，当递归到近义词时，遍历近义词列表算出所有可能。

```python []
class Solution:
    def generateSentences(self, synonyms, text: str):
        self.km={}
        for sy in synonyms:
            ds=None
            if sy[0] in self.km:
                ds=self.km[sy[0]]
                
            else:
                ds=set([])
            ds.add(sy[0])
            ds.add(sy[1])
            self.km[sy[1]]=ds
            self.km[sy[0]]=ds
        self.words=text.split()
        def find(ts,index,count,res):
            if index>=count:
                res.add(ts)
                return
            if index>0:
                ts+=' '
            word=self.words[index]
            index=index+1
            find(ts+word,index,count,res)
            if word in self.km:
                for kw in self.km[word]:
                    find(ts+kw,index,count,res)
        
        res=set([])
        find('',0,len(self.words),res)
        res=list(res)
        res.sort()
        return res
```

