```
class Solution:
    def bonus(self, n: int, leadership: List[List[int]], operations: List[List[int]]) -> List[int]:
        children = collections.defaultdict(list)
        for a, b in leadership:
            children[a].append(b)
        nodes = []
        node_ranges = {}
        def dfs(node):
            nodes.append(node)
            start = len(nodes)
            for child in children[node]:
                dfs(child)
            end = len(nodes)
            node_ranges[node] = (start, end)
        dfs(1)

        tree = Tree(1, n)
        res = []
        for op in operations:
            rg = node_ranges[op[1]]
            if op[0] == 1:
                tree.update(rg[0], rg[0], op[2])
            elif op[0] == 2:
                tree.update(rg[0], rg[1], op[2])
            else:
                res.append(tree.query(rg[0], rg[1]) % 1000000007)
        return res


class Tree:
    def __init__(self, l, r):
        self.l = l
        self.r = r
        self.size = r - l + 1
        self._left = None
        self._right = None
        self.mid = (l + r) // 2
        self.lazy = 0
        self.val = 0

    @property
    def left(self):
        if self._left is None:
            self._left = Tree(self.l, self.mid)
        return self._left

    @property
    def right(self):
        if self._right is None:
            self._right = Tree(self.mid + 1, self.r)
        return self._right

    def update(self, l, r, val):
        if l == self.l and r == self.r:
            self.val += val * self.size
            self.lazy += val
            return
        if self.lazy:
            self.left.lazy += self.lazy
            self.right.lazy += self.lazy
            self.left.val += self.lazy * self.left.size
            self.right.val += self.lazy * self.right.size
            self.lazy = 0
        if r <= self.mid:
            self.left.update(l, r, val)
        elif l >= self.mid + 1:
            self.right.update(l, r, val)
        else:
            self.left.update(l, self.mid, val)
            self.right.update(self.mid + 1, r, val)
        self.val = self.left.val + self.right.val

    def query(self, l, r):
        if l == self.l and r == self.r:
            return self.val
        if self.lazy:
            self.left.lazy += self.lazy
            self.right.lazy += self.lazy
            self.left.val += self.lazy * self.left.size
            self.right.val += self.lazy * self.right.size
            self.lazy = 0
        if r <= self.mid:
            return self.left.query(l, r)
        elif l >= self.mid + 1:
            return self.right.query(l, r)
        else:
            return (
                self.left.query(l, self.mid) +
                self.right.query(self.mid + 1, r)
            )
```
