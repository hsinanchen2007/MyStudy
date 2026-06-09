数据结构用字典，用单词长度做key优化字典

python 用时152ms，提交中击败了97.14%的用户

```
class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data = {}

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        if len(word) in self.data:
            self.data[len(word)] += [word]
        else:
            self.data[len(word)] = [word]


    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        n = len(word)
        if n not in self.data:
            return False
        for w in self.data[n]:
            f = True
            i = 0
            while i < n and f:
                if word[i]!='.' and word[i]!=w[i]:
                    f = False
                i+=1
```

