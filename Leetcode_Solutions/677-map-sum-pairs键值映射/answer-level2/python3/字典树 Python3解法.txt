class MapSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.lookup = {}
        

    def insert(self, key: str, val: int) -> None:
        tree = self.lookup
        for a in key:
            if a not in tree:
                tree[a] = {}
            tree = tree[a]
        # 单词结束标志
        tree["#"] = val
        

    def sum(self, prefix: str) -> int:
        tree = self.lookup
        self.prefixSum = 0
        for a in prefix:
            if a not in tree:
                return self.prefixSum
            tree = tree[a]
        self.recursion(tree)
        return self.prefixSum
        
        
    def recursion(self, tree):
        if not tree:
            return
        for a in tree:
            if a == "#":
                self.prefixSum += tree["#"]
            else:
                self.recursion(tree[a])