BFS 参考了官方题解的邻接表构建
```python
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        # BFS
        from collections import deque, defaultdict
        # 先验判断
        if endWord not in wordList:
            return 0
        # 提前构建邻接表 -> 用generic state做key
        intermidiateWords = defaultdict(list)
        wordLen = len(beginWord)
        for word in wordList:
            for i in range(wordLen):
                intermidiateWords[word[:i] + '*' + word[i+1:]].append(word)
        # 建队列 加初始状态
        queue = deque()
        memo = set()
        queue.append(beginWord)
        memo.add(beginWord)
        step = 1
        while queue:
            size = len(queue)
            for _ in range(size):
                curWord = queue.popleft()
                for i in range(wordLen):
                    intermidiateCurWord = curWord[:i] + '*' + curWord[i+1:]
                    # 下一个状态的所有word
                    for word in intermidiateWords[intermidiateCurWord]:
                        if word == endWord:
                            return step + 1
                        if word not in memo:
                            queue.append(word)
                            memo.add(word)
            step += 1
        else:
            return 0
```
双向BFS就是把Queue 改成 beginQueue 和 endQueue 交替搜索即可，理论上搜索树的深度减少了一半，但是实际试起来比上面的解法慢
```python
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        # BFS
        from collections import deque, defaultdict
        # 先验判断
        if endWord not in wordList:
            return 0
        # 提前构建邻接表 -> 用generic state做key
        intermidiateWords = defaultdict(list)
        wordLen = len(beginWord)
        for word in wordList:
            for i in range(wordLen):
                intermidiateWords[word[:i] + '*' + word[i+1:]].append(word)
        wordLen = len(beginWord)
        beginQueue = deque()
        beginQueue.append(beginWord)
        endQueue = deque()
        endQueue.append(endWord)
        memo = set()
        memo.add(beginWord)
        step = 0
        while beginQueue and endQueue:
            step += 1
            if len(beginQueue) > len(endQueue):
                beginQueue, endQueue = endQueue, beginQueue
            beginLen = len(beginQueue)
            for _ in range(beginLen):
                curWord = beginQueue.popleft()
                for i in range(wordLen):
                    intermidiateCurWord = curWord[:i] +'*' + curWord[i+1:]
                    for word in intermidiateWords[intermidiateCurWord]:
                        if word in endQueue:
                            return step + 1
                        if word not in memo:
                            beginQueue.append(word)
                            memo.add(word)
        else:
            return 0
```
