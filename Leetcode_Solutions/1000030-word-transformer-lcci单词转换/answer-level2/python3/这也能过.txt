### 解题思路
此处撰写解题思路
![11.png](https://pic.leetcode-cn.com/09f182822b38ad49d6ef76f75a49c040580afaf2adfbc8f15ae93a74298e79bd-11.png)

### 代码

```python3
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[str]:
        if endWord not in wordList:return []
        self.dic = dict()
        wordList.sort(key=lambda s:self.distance(s,endWord))
        result = [beginWord]
        if self.find(beginWord,result,wordList):
            return result
        return []
        
    def find(self,beg,result,words)->bool:
        if beg == words[0]:
            return True
        for word in words:
            if self.distance(beg,word) != 1 or word in result: continue
            result.append(word)
            if self.find(word,result,words):
                return True
            result.pop()
        return False
        
        
        
    def distance(self,s1:str,s2:str):
        if (s1,s2) in self.dic:
            return self.dic[(s1,s2)]
        if (s2,s1) in self.dic:
            return self.dic[(s2,s1)]
        dis = sum([0 if s1[i] == s2[i] else 1 for i in range(len(s1))])
        self.dic[(s1,s2)] = self.dic[(s2,s1)] = dis
        return dis
```