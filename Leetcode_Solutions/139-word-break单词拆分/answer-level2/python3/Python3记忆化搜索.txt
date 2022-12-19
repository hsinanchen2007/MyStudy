### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        if not wordDict:
            return False
        dict = set(wordDict)
        memo = {}
        maxLength = max([len(w) for w in dict])
        return self.getResult(s,0,dict,memo,maxLength)
    
    def getResult(self, s, start, set, memo, max):
        if start == len(s):
            return True
        
        if start in memo:
            return memo[start]
        
        for i in range(start, min(start + max + 1, len(s))):
            if s[start:i+1] in set:
                if self.getResult(s,i+1,set,memo,max):
                    memo[start] = True
                    return True
        
        memo[start] = False
        return False
        
        
    
    
    


```