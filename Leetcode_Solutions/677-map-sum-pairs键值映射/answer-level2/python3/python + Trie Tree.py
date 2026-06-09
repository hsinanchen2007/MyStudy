```python
class MapSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.trie = {}

    def insert(self, key: str, val: int) -> None:
        trie = self.trie
        for s in key:
            trie  = trie.setdefault(s, {})
        trie['val'] = val

    def traverse(self, trie):
        tempSum = 0
        if 'val' in trie:
            tempSum += trie['val']
        for key in trie:
            if key == 'val': continue
            tempSum += self.traverse(trie[key])
        return tempSum


    def sum(self, prefix: str) -> int:
        trie = self.trie
        for p in prefix:
            if p not in trie: return 0
            trie = trie[p]
        return self.traverse(trie)
    
# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)
```