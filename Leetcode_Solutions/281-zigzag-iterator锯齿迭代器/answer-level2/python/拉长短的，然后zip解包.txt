```python
class ZigzagIterator(object):

    def __init__(self, v1, v2):
        """
        Initialize your data structure here.
        :type v1: List[int]
        :type v2: List[int]
        """
        self.cur = 0
        len1 = len(v1)
        len2 = len(v2)
        if len1 > len2:
            v2.extend(["#"] * (len1 - len2))
        else:
            v1.extend(["#"] * (len2 - len1))
        z = zip(v1, v2)
        self.it = []
        for i in z:
            if isinstance(i[0], str):
                pass
            else:
                self.it.append(i[0])
            if isinstance(i[1], str):
                pass
            else:
                self.it.append(i[1])

    def next(self):
        """
        :rtype: int
        """
        self.cur += 1
        return self.it[self.cur - 1]

    def hasNext(self):
        """
        :rtype: bool
        """
        return not self.cur == len(self.it)
```
