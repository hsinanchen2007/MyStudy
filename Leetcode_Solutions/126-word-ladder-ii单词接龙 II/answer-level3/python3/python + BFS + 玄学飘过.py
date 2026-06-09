```python
from functools import lru_cache
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:

        @lru_cache(None)
        def getKey(index, curWord):
             return curWord[:index] + '*' + curWord[index + 1:]

        parentNode = collections.defaultdict(list)
        disDict = collections.defaultdict(int)
        wordDict = collections.defaultdict(list)
        wordLength = len(wordList[0])
        for word in wordList:
            disDict[word] = float('inf')
            for i in range(wordLength):
                key = getKey(i, word)
                wordDict[key].append(word)

        queue = collections.deque([(beginWord, 0)])
        disDict[beginWord] = 0
        minDis = float('inf')
       
           
        while queue:
            curWord, curStep = queue.pop()
            for i in range(wordLength):
                key = getKey(i, curWord)
                for nei in wordDict[key]:
                    if curStep + 1 > minDis: continue
                    if curStep + 1 == disDict[nei]:
                        parentNode[nei].append(curWord)
                    elif curStep + 1 < disDict[nei]:
                        queue.append((nei, curStep + 1))
                        parentNode[nei] = [curWord]
                        disDict[nei] = curStep + 1
                    if nei == endWord:
                        minDis = curStep + 1

        def getTransformPath(end, begin, pathArr, tempArr):
            if end == begin:
                path = tempArr + [end]
                pathArr.append(path[::-1])
                return 
            for parent in parentNode[end]:
                tempArr.append(end)
                getTransformPath(parent, begin, pathArr, tempArr)
                tempArr.pop()

        pathArr = []
        getTransformPath(endWord, beginWord, pathArr, [])
        return pathArr
```