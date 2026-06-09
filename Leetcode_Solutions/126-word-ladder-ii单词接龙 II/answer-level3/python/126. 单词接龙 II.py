### 解题思路
- set类型用add()方法；
- set(['ab']) = {'ab'}；
- set('ab') = {'a', 'b'}；

### 代码

```python3
class Solution:
    def findLadders(self, beginWord, endWord, wordList):
        res = []
        cur = set([beginWord])
        dic = set(wordList) | set([beginWord])
        routine = {word : [] for word in dic}

        def backtrack(res, path, routine, endWord):
            if len(routine[endWord]) == 0:
                res.append([endWord] + path)
            else:
                for word in routine[endWord]:
                    backtrack(res, [endWord] + path, routine, word)

        while cur and endWord not in cur:
            nextword = set()
            for word in cur:
                dic.remove(word)
            for word in cur:
                for i in range(len(beginWord)):
                    for j in range(97, 123):
                        tmp = word[:i] + chr(j) + word[i + 1:]
                        if tmp in dic:
                            nextword.add(tmp)
                            routine[tmp].append(word)
            cur = nextword

        if cur:
            backtrack(res, [], routine, endWord)
        
        return res
```