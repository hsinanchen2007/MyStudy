### 解题思路
- 注意：是求转换序列的长度；
- 有可能会有多个单词符合的情况；
- 要先入先出，确保找到最短的单词转换序列；

### 代码

```python3
class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int: 
        word_set = set(wordList)
        if beginWord == endWord:
            return 0
        if endWord not in word_set:
            return 0
        stack = [(1, beginWord)]
        n = len(beginWord)
        while stack:
            step, word = stack.pop(0)
            for i in range(n):
                for j in 'abcdefghijklmnopqrstuvwxyz':
                    new = word[:i] + j + word[i + 1:]
                    if new == endWord:
                        return step + 1
                    if new in word_set:
                        word_set.remove(new)     
                        stack.append((step + 1, new))
        return 0
                     


```