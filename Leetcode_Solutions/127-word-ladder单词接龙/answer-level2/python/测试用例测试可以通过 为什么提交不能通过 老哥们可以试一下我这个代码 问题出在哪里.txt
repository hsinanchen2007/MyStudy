"hot"
"dog"
["hot","dog","dot"]

```
class Solution(object):
    def __init__(self):
        self.map = {}
        self.step = float("inf")
    def isNeigbor(self,word1,word2):
        sum = 0
        for i in range(len(word1)):
            if word1[i] != word2[i]:
                sum += 1
        return sum == 1
    def walk(self,beginWord,endWord,step = 1,footprint =[]):
        if beginWord == endWord and step < self.step:
            self.step = step
            print(footprint)
            return
        if beginWord == []:
            return

        footprint.append(beginWord)
        for ele in (set(self.map[beginWord])-set(footprint)):
            self.walk(ele,endWord,step+1,footprint)
    def ladderLength(self, beginWord, endWord, wordList):
        if endWord not in wordList:
            return 0
        if beginWord not in wordList:
            wordList.append(beginWord)
        for i in range(len(wordList)):
            self.map[wordList[i]] = []
        for i in range(len(wordList)):
            for j in range(i+1,len(wordList)):
                if self.isNeigbor(wordList[i],wordList[j]):
                    self.map[wordList[i]].append(wordList[j])
                    self.map[wordList[j]].append(wordList[i])
        self.walk(beginWord,endWord)
        if self.step != float('inf'):
            return self.step
        return 0

```