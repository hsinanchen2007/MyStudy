```
class MapSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.trie = {}

    def insert(self, key: str, val: int) -> None:
        node = self.trie
        for c in key:
            node = node.setdefault(c, {})
        node['#'] = val

    def sum(self, prefix: str) -> int:
        nodes = self.trie
        for c in prefix:
            if c in nodes:
                nodes = nodes[c]
            else:
                return 0

        def dfs(nodes):
            val = nodes.get('#', 0)
            s = val
            for c in nodes:
                if c != '#':
                    s += dfs(nodes[c])
            return s

        return dfs(nodes)
```
