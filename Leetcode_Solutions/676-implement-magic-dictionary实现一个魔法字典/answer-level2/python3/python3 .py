```
class MagicDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.trie = {}  

    def buildDict(self, words: List[str]) -> None:
        """
        Build a dictionary through a list of words
        """
        trie = node = self.trie
        for w in words:
            for c in w:
                # node = node.setdefault(c, {})
                if c not in node:
                    node[c] = {}
                node = node[c]
            node['is_word'] = {}
            node = trie

    def search(self, word: str) -> bool:
        """
        Returns if there is any word in the trie that equals to the given word after modifying exactly one character
        """
        def find(word, node):
            for u in word:
                if u not in node:
                    return False
                node=node[u]
            return 'is_word' in node 

        def searchResult(word, node, diff):
            if not word:
                return diff==1 and 'is_word' in node
            res = False
            if diff: # 已有一位字符与word不同
                return find(word, node)
            for u in node:
                res |= searchResult(word[1:], node[u], 0 if word[0]==u else 1)
            return res
        return searchResult(word, self.trie, 0)
```
