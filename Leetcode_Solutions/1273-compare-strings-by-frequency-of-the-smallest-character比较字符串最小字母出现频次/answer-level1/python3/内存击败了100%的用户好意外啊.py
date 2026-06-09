![image.png](https://pic.leetcode-cn.com/db356426e29ed84965194ae3426072cee08f84c44f1393b61c351437407466fa-image.png)

```python []
class Solution:
    def count(self,word):
        alpha = 'abcdefghijklmnopqrstuvwxyz'
        for i in alpha:
            if i in word:
                return word.count(i)
    
    def wordnum(self,wcount,wordscount):
        n = 0 
        for i in wordscount:
            if i > wcount:
                n += 1
        return n
    
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        res = []
        wordscount = []
        l = len(words)
        for w in words:
            wordscount.append(self.count(w))
            
            
        for w in queries:
            wcount = self.count(w)
            res.append(self.wordnum(wcount,wordscount))
        
        return res
            
```
