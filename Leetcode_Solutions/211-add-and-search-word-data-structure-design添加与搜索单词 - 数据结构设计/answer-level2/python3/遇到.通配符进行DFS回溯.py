### 解题思路
此处撰写解题思路

### 代码

```python3
class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.children={}
        self.end = False
        

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        root = self
        for c in word:
            if c not in root.children:
                root.children[c] =WordDictionary()
            root= root.children[c]
        root.end = True 

        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        
        def dfs_search(root:WordDictionary,start:int,word:str):
            if start==len(word):
                return root.end
            if word[start] in root.children:
                return dfs_search(root.children[word[start]],start+1,word)
            elif word[start] == '.':
                for i in root.children.keys():
                    if dfs_search(root.children[i],start+1,word) is True:
                        return True
                return False
            else:
                return False

        return dfs_search(self,0,word)
                

        


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
```