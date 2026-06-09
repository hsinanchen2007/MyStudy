```python

class Trie:
    
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.dic = {}
        

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        dic = self.dic
        for w in word:
            if w not in dic:
                dic[w] = {}
            dic = dic[w]
        dic['flag'] = True # 用来判断这个节点是不是根节点
            
        
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        dic = self.dic
        for w in word:
            if w not in dic:
                return False
            dic = dic[w]

        return 'flag' in dic # 返回这个节点是不是根节点
        
        
    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        dic = self.dic
        for w in prefix:
            if w not in dic:
                return False
            dic = dic[w]
        return True

```
