### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        wordList = set(wordList)
        if endWord not in wordList:
            return []
        queue = [[beginWord, [beginWord]]]
        levelWords = set([beginWord])
        res = []
        stopFlag = False
        # hashtable to store neighbor nodes
        hashTable = dict()
        while queue:
            nextQueue = []
            nowLevelWords = set()
            for i in range(len(queue)):
                word, path = queue[i]
                if word == endWord:
                    stopFlag=True
                    res.append(path)
                    continue
                # find neighbors
                candidates = []
                if word in hashTable:
                    candidates = hashTable[word]
                
                for ichar in range(len(word)):
                    for exchangej in range(ord('a'), ord('z')+1):
                        candidate = word[:ichar]+chr(exchangej)+word[(ichar+1):]
                        if word[ichar]!=chr(exchangej) and candidate in wordList:
                            candidates.append(candidate)
                # next level
                for candidate in candidates:
                    if candidate not in levelWords:
                        nowLevelWords.add(candidate)
                        nextQueue.append([candidate, path+[candidate]])
            if stopFlag:
                return res
            
            queue = nextQueue
            levelWords.update(nowLevelWords)
                

                    

        


        
```