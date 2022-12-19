```
class ZigzagIterator(object):

    def __init__(self, v1, v2):
        """
        Initialize your data structure here.
        :type v1: List[int]
        :type v2: List[int]
        """
        self.curr = 0
        self.len = 2
        self.idx = [0,0]
        self.nums = [v1,v2]

    def next(self):
        """
        :rtype: int
        """
        now = self.curr
        while self.idx[now] == len(self.nums[now]):
            now = (now + 1)%self.len
        res = self.nums[now][self.idx[now]]
        self.idx[now] += 1
        self.curr = (now + 1)%self.len
        return res

    def hasNext(self):
        """
        :rtype: bool
        """
        for i in range(len(self.idx)):
            if self.idx[i] != len(self.nums[i]):
                return True
        return False

# Your ZigzagIterator object will be instantiated and called as such:
# i, v = ZigzagIterator(v1, v2), []
# while i.hasNext(): v.append(i.next())
```