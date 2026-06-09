### 解题思路
#### 初始化
使用defaultdict(list)初始化root节点，root节点以单词的长度为键，单词为值，构建了层数为2的一个N叉树。
#### add_word
如果单词存在，则把单词加到N叉树中。
```
self.root[len(word)].append(word)
```
#### search
分为三种情况
##### 1.word为空
直接返回False
##### 2.word无"."
直接看word是否存在于root[len(word)]中
##### 3.word有"."
遍历root[len(word)]中的单词，其中每个单词与word逐个字母比较，如果字母不相等且无"."则返回False,否则遍历完查到则返回True。
### 代码

```python3
from collections import defaultdict
class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root=defaultdict(list)#以单词的长度为键，单词为值

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        if word:
            self.root[len(word)].append(word)

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        if not word:return False
        if "." not in word:return word in self.root[len(word)]
        # match xx.xx.x with yyyyyyy
        for v in self.root[len(word)]:
            # match xx.xx.x with yyyyyyy
            for i, ch in enumerate(word):
                if ch != v[i] and ch != '.':
                    break
            else:
                return True
        return False



# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
```