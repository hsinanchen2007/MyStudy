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
        双向BFS
        """
        wordList = set(wordList)
        if endWord not in wordList:
            return 0
        neighbors = dict()
        # 寻找单词的邻接点
        def findNeighbors(word):
            if word in neighbors:
                return neighbors[word]
            candidates = []
            for i in range(len(word)):
                for exchangej in range(ord('a'), ord('z')+1):
                    candidate = word[:i]+chr(exchangej)+word[(i+1):]
                    if word[i]!=chr(exchangej) and candidate in wordList:
                        candidates.append(candidate)
            neighbors[word] = candidates
            return candidates
        
        beginWord_queue, endWord_queue = [beginWord], [endWord]
        # 记录begin，end每一层用过的单词
        begin_levels = {1:[beginWord]}
        end_levels = {1:[endWord]}
        # 记录begin，end用过的单词
        begin_visited,end_visited = set([beginWord]), set([endWord])

        # 寻在单词在一个层次遍历中的层数（已知单词在这个层次遍历序列中了）
        def findInLevel(word, level_dict):
            for i in range(1,len(level_dict)+1):
                words = level_dict[i]
                if word in words:
                    return i


        # 双向BFS，先开始begin端
        while beginWord_queue and endWord_queue:
            next_queue = []
            for word in beginWord_queue:

                candidates = findNeighbors(word)
                for candidate in candidates:
                    #单词在end端出现，返回begin端完整遍历层数+单词在end端的层
                    if candidate in end_visited:
                        return  len(begin_levels)+findInLevel(candidate, end_levels)
                    if candidate in begin_visited:
                        continue
                    begin_visited.add(candidate)
                    next_queue.append(candidate)
            begin_levels[len(begin_levels)+1] = next_queue
            beginWord_queue = next_queue
            # 交换让end端BFS
            beginWord_queue, endWord_queue = endWord_queue,beginWord_queue
            begin_levels,end_levels = end_levels,begin_levels
            begin_visited,end_visited = end_visited, begin_visited

        return 0



        



        
```