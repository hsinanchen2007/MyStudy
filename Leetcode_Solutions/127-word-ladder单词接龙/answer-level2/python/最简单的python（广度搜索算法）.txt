### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        wordList=set(wordList)
        q=[(beginWord,1)]
        if endWord not in wordList:
            return 0
        while q:
            node,level=q.pop(0)
            if node == endWord:
                return level
            for i in range(len(node)):
                for j in "abcdefghijklmnopqrstuvwxyz":
                    new=node[:i]+j+node[i+1:]
                    if new in wordList:
                        q.append((new,level+1))
                        wordList.remove(new)
        return 0


```