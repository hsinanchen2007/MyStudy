执行时间超过96.64%的用户，分享一下，看哪里可以优化不
```
from collections import defaultdict
class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        tree = defaultdict(list)
        for s in allowed:
            tree[s[0:2]].append(s[2])
        return self.work(bottom, tree, 0)
    def work(self, bottom, tree, pos):
        if pos == len(bottom) - 1:
            pos = 0
            bottom = bottom[:-1]
        if len(bottom) <= 1:
            return True
        if bottom[pos:pos+2] not in tree.keys():
            return False
        for value in tree[bottom[pos:pos+2]]:
            btm = bottom[:pos] + value + bottom[pos+1:]
            if self.work(btm, tree, pos + 1):
                return True
        return False
```
