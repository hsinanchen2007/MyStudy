1.用字典存储树，采用$符号表示该节点是一个word的末尾字符；
2.采用非递归DFS实现匹配搜索；
```python
class WordDictionary:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.ch_tree = {}  # like {'a': {'$': {}, 'b': {'$': {}}}}


    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        """
        cu = self.ch_tree
        for ch in word:
            cu = cu.setdefault(ch, {})
        cu['$'] = {}  # with {'a': {'$': {}, 'b': {'$': {}}}} , mean include 'a', 'ab'

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        """
        res = self.dfs([(iter([self.ch_tree]), word)])
        return res

    @staticmethod
    def dfs(stack):
        while stack:
            trees, word = stack[-1]
            try:
                tree = next(trees)
            except StopIteration:
                del stack[-1]
                continue
            if word[0] == '.' or word[0] in tree:
                new_trees = tree.values() if word[0] == '.' else [tree[word[0]]]
                if len(word) > 1:
                    stack.append((iter(new_trees), word[1:]))
                elif any('$' in new_tree for new_tree in new_trees):
                    return True
        return False
```
