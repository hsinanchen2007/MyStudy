BFS模板参见个人博客：https://blog.csdn.net/qq_19446965/article/details/102739705
**分享解题过程**：
开始尝试字典+判断：
```
def judge_same(str1, str2):
        n = 0
        for ch1, ch2 in zip(str1, str2):
            if ch1 != ch2:
                n += 1
            if n > 1:
                return False
        return n == 1

    maps = {}
    for i in range(len(wordList)):
        for j in range(i + 1, len(wordList)):
            if judge_same(wordList[i], wordList[j]):
                if maps.get(wordList[i]):
                    maps.get(wordList[i]).append(wordList[j])
                else:
                    maps[wordList[i]] = [wordList[j]]
                if maps.get(wordList[j]):
                    maps.get(wordList[j]).append(wordList[i])
                else:
                    maps[wordList[j]] = [wordList[i]]
    print(maps)
```

尝试好几次不过。。。过了29/39,,,大约5秒

接着尝试。。。不用字典的，每一次添加节点都搜一遍

    def get_next_words(word, wordList):
        words = []
        for next_word in wordList:
            if next_word != word and judge_same(word, next_word):
                words.append(next_word)
        return words
我去30多秒。。。还是不过

接着尝试其他人的方法：

    def get_next_words(word, wordList):
        words = []
        for i in range(len(word)):
            for c in 'abcdefghijklmnopqrstuvwxyz':
                next_word = word[:i] + c + word[i + 1:]
                if next_word != word and next_word in wordList:
                    words.append(next_word)
        return words
更慢了，，，1分钟跑不完，，，要爆炸了。。。

再审审题，，，我去，，，这个题变态地方在字典，说是字典给的却是list

于是，有了画龙点睛之笔：dict = set(wordList)

    def get_next_words(word, dict):
        words = []
        for i in range(len(word)):
            for c in 'abcdefghijklmnopqrstuvwxyz':
                next_word = word[:i] + c + word[i + 1:]
                if next_word != word and next_word in dict:
                    words.append(next_word)
        return words
终于过了，，，其实BFS还有好多的记忆搜索的优化，，不再赘述，，，

全代码如下：

```
def findLadders(beginWord, endWord, wordList):
    """
    :type beginWord: str
    :type endWord: str
    :type wordList: List[str]
    :rtype: List[List[str]]
    """

    def get_next_words(word, dict):
        words = []
        for i in range(len(word)):
            for c in 'abcdefghijklmnopqrstuvwxyz':
                next_word = word[:i] + c + word[i + 1:]
                if next_word != word and next_word in dict:
                    words.append(next_word)
        return words 
        if endWord not in wordList:
            return []
        
        dict = set(wordList)           
        queue = [(beginWord, [beginWord])]
        res = {}          # 存储结果
        depth = 0         # 深度，用于去除重复判断
        distance = {}     # 用于存储节点在哪一层遍历了
        min_len = float('inf')
        while queue:
            depth += 1
            new_queue = []
            for cur, path in queue:
                if cur == endWord:
                    if len(path) < min_len:
                        min_len = len(path)
                        res[min_len] = [path]
                    else:
                        res.get(min_len).append(path)
                        continue
                    
                for next in get_next_words(cur, dict):
                    if distance.get(next) and distance.get(next) < depth: # 前一层已经遍历过，无需再遍历
                        continue
                    distance[next] = depth
                    if len(path) + 1 > min_len:    # 取长度小的
                        continue
                    if next not in path: 
                        new_queue.append((next, path + [next]))
                        
            queue = new_queue
        
        return res.get(min_len)
```
————————————————

BFS模板参见个人博客：https://blog.csdn.net/qq_19446965/article/details/102739705