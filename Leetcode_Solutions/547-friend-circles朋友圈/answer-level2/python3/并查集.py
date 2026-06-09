```
class Solution:

    def __init__(self):
        self.pre = []

    def findCircleNum(self, M: List[List[int]]) -> int:

        self.pre = [False] * len(M)
        for i in range(len(M)):
            for j in range(i):
                if M[i][j] == 1:
                    self.joinNum(i, j)
        cnt = 0
        for i in self.pre:
            if i is False:
                cnt += 1
        return cnt
        pass

    def unionSearch(self, root):

        child = root
        while self.pre[root] is not False:
            root = self.pre[root]
        while child != root:
            tmp = self.pre[child]
            self.pre[child] = root
            child = tmp
        return root
        pass

    def joinNum(self, root1, root2):
        x = self.unionSearch(root1)
        y = self.unionSearch(root2)
        if x != y:
            self.pre[x] = y
        pass
```