```
class MapSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.lookup = {}

    def insert(self, key: str, val: int) -> None:
        tree = self.lookup
        for c in key:
            if c not in tree:
                tree[c] = {}
            tree = tree[c]
        tree['#'] = val  

    def sum(self, prefix: str) -> int:
        tree = self.lookup
        for c in prefix:
            if c not in tree:
                return 0
            tree = tree[c]
        self.res = 0

        def dfs(tree):
            if type(tree) is not dict:
                return
            
            if '#' in tree:
                self.res += tree['#']            
            for k in tree:
                dfs(tree[k])
        
        dfs(tree)
        return self.res

# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)
```
