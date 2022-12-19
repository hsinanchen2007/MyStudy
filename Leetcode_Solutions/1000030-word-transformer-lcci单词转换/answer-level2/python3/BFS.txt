计算当前单词的所有可行的变词, 当字典很大的时候其复杂度会远远小于遍历整个字典找所有变词

```python
class Solution:
    def findLadders(self, beginWord: str, endWord: str,
                    wordList: List[str]) -> List[str]:
        # BFS, 找到当前字符串的所有变词, 检查是否在字典中, 在的话加入q
        # 需要使用一个pre字典记录当前单词的上一个单词
        v = set(wordList)
        if endWord not in v:
            return []
        chrs = set()
        for w in wordList:
            for c in w:
                chrs.add(c)
        if beginWord in v:
            v.remove(beginWord)
        q = [beginWord]
        pre = {}

        def findNexts(s):
            for i, c in enumerate(s):
                for newc in chrs:
                    if newc != c:
                        news = s[0:i] + newc + s[i + 1:]
                        if news in v:
                            v.remove(news)
                            q.append(news)
                            pre[news] = s

        for s in q:
            if s == endWord:
                res = []
                cur = s
                while cur in pre and cur != beginWord:
                    res.append(cur)
                    cur = pre[cur]
                if cur == beginWord:
                    res.append(cur)
                    return res[::-1]
            findNexts(s)
        return []
```
