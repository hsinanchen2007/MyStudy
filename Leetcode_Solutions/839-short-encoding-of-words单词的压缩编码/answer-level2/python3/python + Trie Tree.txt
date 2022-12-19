```
class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        root = {}
        words = sorted(list(set(words)), key=len, reverse=True)
        rst = 0
        for word in words:
            new_word = False
            node = root
            for i in word[::-1]:
                if i not in node:
                    new_word = True
                    node[i] = {}
                node = node[i]
            if new_word:
                rst = rst + len(word) + 1
        return rst
```
什么是 Trie Tree，为什么这里可以用Trie Tree，大家可以去看官方题解。这里只是针对官方不那么容易理解的python代码，提供了一种较易理解的写法。

首先在单词去重后我们按单词长度逆序排序。这样从长单词开始插入树（逆序插入，如 time变为emit插入），当短一点的单词插入时，如果是前缀，则不需做任何操作，只是一系列检查而已（如me，则 em已是emit的前缀）。因此，我们可以设置标志位``new_word``，当需要做插入操作时，表示我们遇到了新的单词，此时把``new_word ``置为``True``，当一个单词插入结束后，只有标志位为``True``，我们我们才把其长度加到结果``rst``中（加的1为单词末尾'#'的长度）。