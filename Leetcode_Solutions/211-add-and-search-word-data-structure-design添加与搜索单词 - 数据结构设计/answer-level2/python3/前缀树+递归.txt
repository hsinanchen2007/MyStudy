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
        tree = self.data
        for w in word:
            if w not in tree:
                tree[w] = {}

            tree = tree[w]
        tree["#"] = {}
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        tree = self.data
        def help(tree, word):
            #递归结束条件
            if not word:
                if "#" in tree:
                    return True
                else :
                    return False
            #如果遇到.，对该分支所有点进行递归，只有有一个返回True即可
            if word[0] == '.':
                tmp = [help(tree[key], word[1:]) for key in tree]
                return any(tmp)
            #如果不是.,比较该节点并递归下一节点
            else:
                return word[0] in tree and help(tree[word[0]], word[1:])

        return help(tree, word)
```
