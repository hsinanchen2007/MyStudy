```python
class MapSum:

    def __init__(self,isword=False):
        self.isword = isword
        self.children = {}

    def insert(self, key: str, val: int) -> None:
        cur = self.children
        for i,v in enumerate(key):
            if v not in cur:
                cur[v] = MapSum()
            if i==len(key)-1:
                cur[v].isword = val
            cur = cur[v].children

    def sum(self, prefix: str) -> int:
        cur,rst = self.children,0
        for i,v in enumerate(prefix):
            if v not in cur:
                return 0
            if i==len(prefix)-1:
                rst = cur[v].isword
            cur = cur[v].children
        stack = list(cur.values())
        while stack:
            v = stack.pop()
            rst += v.isword
            stack.extend(v.children.values())
        return rst
# 执行用时 :28 ms, 在所有 Python3 提交中击败了96.06%的用户
# 内存消耗 :13 MB, 在所有 Python3 提交中击败了52.43%的用户
```