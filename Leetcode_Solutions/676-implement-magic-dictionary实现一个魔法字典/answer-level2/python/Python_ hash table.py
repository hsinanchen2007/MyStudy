### 解题思路
hash table存储字典，用单词长度作为key，单词作为value。
### 代码

```python
class MagicDictionary:
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.dic = {}

    def buildDict(self, dict: List[str]) -> None:
        """
        Build a dictionary through a list of words
        """
        for w in dict:
            self.dic[len(w)] = self.dic.get(len(w), []) + [w]

    def search(self, word: str) -> bool:
        """
        Returns if there is any word in the trie that equals to 
        the given word after modifying exactly one character
        """
        if len(word) in self.dic:
            for w in self.dic[len(word)]:
                cnt = 0
                for i in range(len(w)):
                    if word[i] != w[i]:
                        cnt +=1
                        if cnt > 1: break
                if cnt == 1: return True
        return False

```