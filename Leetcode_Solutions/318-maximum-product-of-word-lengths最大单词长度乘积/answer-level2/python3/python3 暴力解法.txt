
暴力解法



```python []
class Solution:
    def check(self,word1,word2):
        for i in word1:
            if i in word2:
                return False
        return True
    
    def maxProduct(self, words: List[str]) -> int:
        res = 0
        length = len(words)
        for i in range(length):
            for j in range(i,length):
                if self.check(words[i],words[j]):
                    res = max(res, len(words[i])*len(words[j]))
        
        return res
```
