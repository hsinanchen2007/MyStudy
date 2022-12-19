### 解题思路
我尝试了几种解法：
1. 我个人最容易想到的回溯，可以解，但是严重超时；
2. 基础的bfs，预先计算所有字符串之间的关系，并用map存储，还是超时；
3. 后来我看了一个解答，发现答主在计算两个字符串的是否只差一个字符的方法很有趣，学习了一下，就过了；

然后，我验证了一下程序最好时的地方，不是bfs，而是计算相似性上。下面是我的方法。
```python
    def one_hop(word_a, word_b):
        cnt = 0
        for i in xrange(len(word_a)):
            if word_a[i] != word_b[i]:
                cnt = cnt + 1
                if cnt >= 2:
                    return False
        return True
    rel = {}
    flag = {}
    for i in xrange(len(wordList)):
        flag[wordList[i]] = False
        if beginWord not in rel:
            rel[beginWord] = []
        if one_hop(beginWord, wordList[i]):
            rel[beginWord].append(wordList[i])
        for j in xrange(i+1, len(wordList)):
            if wordList[i] not in rel:
                rel[wordList[i]] = []
            if wordList[j] not in rel:
                rel[wordList[j]] = []
            if one_hop(wordList[i], wordList[j]):
                rel[wordList[i]].append(wordList[j])
                rel[wordList[j]].append(wordList[i])
```

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
        word_set = set(wordList)
        if beginWord == endWord:
            return 0
        if endWord not in word_set:
            return 0
        cnt = len(beginWord)
        q = [(1, beginWord)]
        while q:
            layer, node = q.pop(0)
            for i in xrange(cnt):
                for j in 'abcdefghijklmnopqrstuvwxyz':
                    # 构造与 node 只相差一个字符的字符串
                    new = node[:i] + j + node[(i+1):]
                    if new == endWord:
                        return layer + 1
                    if new in word_set:
                        word_set.remove(new)
                        q.append((layer +1, new))
        return 0


```